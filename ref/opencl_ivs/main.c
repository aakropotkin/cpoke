
#define CL_TARGET_OPENCL_VERSION 120

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

static const size_t MAX_SRC_SIZE     = 0x100000;
static const size_t LIST_SIZE_S      = 16 * 16 * 16;
static const size_t LIST_SIZE_CPMS   = 79;
static const size_t LIST_SIZE_CPS    = LIST_SIZE_S * LIST_SIZE_CPMS;
static const size_t CHUNK_SIZE       = 64;
static const size_t BUFFER_SIZE_S    = LIST_SIZE_S * sizeof( char );
static const size_t BUFFER_SIZE_CPMS = LIST_SIZE_CPMS * sizeof( double );
static const size_t BUFFER_SIZE_CPS  = LIST_SIZE_CPS * sizeof( short );

static const double CPMS[] = {
  0.09399997, 0.13513743, 0.16639787, 0.19265091, 0.21573247, 0.23657266,
  0.25572005, 0.27353038, 0.29024988, 0.30605738, 0.32108760, 0.33544503,
  0.34921268, 0.36245775, 0.37523559, 0.38759241, 0.39956728, 0.41119355,
  0.42250001, 0.43292641, 0.44310755, 0.45305996, 0.46279839, 0.47233608,
  0.48168495, 0.49085581, 0.49985844, 0.50870176, 0.51739395, 0.52594251,
  0.53435433, 0.54263576, 0.55079269, 0.55883060, 0.56675452, 0.57456915,
  0.58227891, 0.58988791, 0.59740001, 0.60482366, 0.61215729, 0.61940412,
  0.62656713, 0.63364918, 0.64065295, 0.64758096, 0.65443563, 0.66121926,
  0.66793400, 0.67458190, 0.68116492, 0.68768490, 0.69414365, 0.70054289,
  0.70688421, 0.71316910, 0.71939909, 0.72557561, 0.73170000, 0.73474101,
  0.73776948, 0.74078557, 0.74378943, 0.74678120, 0.74976104, 0.75272910,
  0.75568551, 0.75863037, 0.76156384, 0.76448607, 0.76739717, 0.77029727,
  0.77318650, 0.77606494, 0.77893275, 0.78179006, 0.78463697, 0.78747358,
  0.79030001, 0.79280395, 0.79530001, 0.79780392, 0.80030000, 0.80280389,
  0.80530000, 0.80780386, 0.81029999, 0.81280383, 0.81529999
};

  int
main( int argc, char * argv[], char ** envp )
{
  FILE             * fp               = NULL;
  char             * src_str          = NULL;
  cl_command_queue   cmd_queue        = NULL;
  cl_context         context          = NULL;
  cl_device_id       device_id        = NULL;
  cl_kernel          kernel           = NULL;
  //cl_mem             batk_mem_obj     = NULL;
  //cl_mem             bsta_mem_obj     = NULL;
  //cl_mem             cdef_mem_obj     = NULL;
  cl_mem             iv_atks_mem_obj  = NULL;
  cl_mem             iv_stas_mem_obj  = NULL;
  cl_mem             iv_defs_mem_obj  = NULL;
  cl_mem             cpms_mem_obj     = NULL;
  cl_mem             cps_mem_obj      = NULL;
  cl_platform_id     platform_ids[2]  = { NULL, NULL };
  cl_program         program          = NULL;
  cl_uint            rsl_num_devs     = 0;
  cl_uint            rsl_num_plats    = 0;
  cl_int             rsl              = CL_INVALID_VALUE;
  int                estatus          = EXIT_FAILURE;
  int                i                = 0;
  unsigned char      base_atk         = 0;
  unsigned char      base_sta         = 0;
  unsigned char      base_def         = 0;
  unsigned char    * iv_atks          = NULL;
  unsigned char    * iv_stas          = NULL;
  unsigned char    * iv_defs          = NULL;
  unsigned short   * cps              = NULL;
  size_t             global_item_size = LIST_SIZE_CPS;
  size_t             local_item_size  = CHUNK_SIZE;
  size_t             src_size         = 0;

  /* Allocate buffers */
  iv_atks = (unsigned char *) malloc( BUFFER_SIZE_S );
  if ( iv_atks == NULL ) return EXIT_FAILURE;

  iv_stas = (unsigned char *) malloc( BUFFER_SIZE_S );
  if ( iv_stas == NULL ) goto free_mallocs;

  iv_defs = (unsigned char *) malloc( BUFFER_SIZE_S );
  if ( iv_defs == NULL ) goto free_mallocs;

  cps = (unsigned short *) malloc( BUFFER_SIZE_CPS );
  if ( cps == NULL ) goto free_mallocs;

  src_str = (char *) malloc( MAX_SRC_SIZE );
  if ( src_str == NULL ) goto free_mallocs;

  /* Load Kernel Source */
  fp = fopen( "cp_from_stats.cl", "r" );
  if ( fp == NULL )
    {
      fprintf( stderr, "Failed to load kernel.\n" );
      goto free_mallocs;
    }
  src_size = fread( src_str, 1, MAX_SRC_SIZE, fp );
  assert( 0 < src_size );
  fclose( fp );

  /* Get Platform Device Information */
  rsl = clGetPlatformIDs( 1, platform_ids, & rsl_num_plats );
  assert( rsl == CL_SUCCESS );

  rsl = clGetDeviceIDs( platform_ids[0],
                        CL_DEVICE_TYPE_DEFAULT,
                        1,
                        & device_id,
                        & rsl_num_devs
                      );
  assert( rsl == CL_SUCCESS );

  /* Create OpenCL Context */
  context = clCreateContext( NULL, 1, & device_id, NULL, NULL, & rsl );
  assert( rsl == CL_SUCCESS );

  /* Create a Command Queue */
  cmd_queue = clCreateCommandQueue( context, device_id, 0, & rsl );
  assert( rsl == CL_SUCCESS );

  /* Create Memory Buffers on the Device for each Vector */
  iv_atks_mem_obj = clCreateBuffer( context,
                                    CL_MEM_READ_ONLY,
                                    BUFFER_SIZE_S,
                                    NULL,
                                    & rsl
                                  );
  assert( rsl == CL_SUCCESS );
  iv_stas_mem_obj = clCreateBuffer( context,
                                    CL_MEM_READ_ONLY,
                                    BUFFER_SIZE_S,
                                    NULL,
                                    & rsl
                                  );
  assert( rsl == CL_SUCCESS );
  iv_defs_mem_obj = clCreateBuffer( context,
                                    CL_MEM_WRITE_ONLY,
                                    BUFFER_SIZE_S,
                                    NULL,
                                    & rsl
                                  );
  assert( rsl == CL_SUCCESS );
  cpms_mem_obj = clCreateBuffer( context,
                                 CL_MEM_WRITE_ONLY,
                                 BUFFER_SIZE_CPMS,
                                 NULL,
                                 & rsl
                               );
  assert( rsl == CL_SUCCESS );
  cps_mem_obj = clCreateBuffer( context,
                                CL_MEM_WRITE_ONLY,
                                BUFFER_SIZE_CPS,
                                NULL,
                                & rsl
                              );
  assert( rsl == CL_SUCCESS );

  /* Fill lists/arg data */
  base_atk = 198;
  base_sta = 190;
  base_def = 189;
  i = 0;
  for ( unsigned char a = 0; a <= 15; a++ )
    {
      for ( unsigned char s = 0; s <= 15; s++ )
        {
          for ( unsigned char d = 0; d <= 15; d++ )
            {
              iv_atks[i] = a;
              iv_stas[i] = s;
              iv_defs[i] = d;
            }
        }
    }

  /* Load lists of stats/cpms to device */
  rsl = clEnqueueWriteBuffer( cmd_queue,
                              iv_atks_mem_obj,
                              CL_TRUE,
                              0,
                              BUFFER_SIZE_S,
                              iv_atks,
                              0,
                              NULL,
                              NULL
                            );
  assert( rsl == CL_SUCCESS );

  rsl = clEnqueueWriteBuffer( cmd_queue,
                              iv_stas_mem_obj,
                              CL_TRUE,
                              0,
                              BUFFER_SIZE_S,
                              iv_stas,
                              0,
                              NULL,
                              NULL
                            );
  assert( rsl == CL_SUCCESS );

  rsl = clEnqueueWriteBuffer( cmd_queue,
                              iv_defs_mem_obj,
                              CL_TRUE,
                              0,
                              BUFFER_SIZE_S,
                              iv_defs,
                              0,
                              NULL,
                              NULL
                              );
  assert( rsl == CL_SUCCESS );

  rsl = clEnqueueWriteBuffer( cmd_queue,
                              cpms_mem_obj,
                              CL_TRUE,
                              0,
                              BUFFER_SIZE_CPMS,
                              CPMS,
                              0,
                              NULL,
                              NULL
                              );
  assert( rsl == CL_SUCCESS );

  /* Create a Program from the Kernel Source */
  program = clCreateProgramWithSource( context,
                                       1,
                                       (const char **)  & src_str,
                                       (const size_t *) & src_size,
                                       & rsl
                                     );
  assert( rsl == CL_SUCCESS );

  /* Build the program */
  rsl = clBuildProgram( program, 1, & device_id, NULL, NULL, NULL );
  if ( rsl == CL_BUILD_PROGRAM_FAILURE )
    {
      /* Determine the size of the log */
      size_t log_size;
      clGetProgramBuildInfo( program,
                             device_id,
                             CL_PROGRAM_BUILD_LOG,
                             0,
                             NULL,
                             & log_size
                           );

      /* Allocate memory for the log */
      char * log = (char *) malloc( log_size );

      /* Get the log */
      clGetProgramBuildInfo( program,
                             device_id,
                             CL_PROGRAM_BUILD_LOG,
                             log_size,
                             log,
                             NULL
                           );

      /* Print the log */
      fprintf( stderr, "%s\n", log );
    }
  assert( rsl == CL_SUCCESS );

  /* Create the OpenCL Kernel */
  kernel = clCreateKernel( program, "cp_from_stats", & rsl );
  if ( rsl != CL_SUCCESS ) printf( "ERR: %d\n", rsl );
  assert( rsl == CL_SUCCESS );

  /* Set the Arguments of the Kernel */
  rsl = clSetKernelArg( kernel, 0, sizeof( char ), (void *) & base_atk );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 1, sizeof( char ), (void *) & base_sta );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 2, sizeof( char ), (void *) & base_def );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 3, sizeof( cl_mem ), (void *) & iv_atks_mem_obj );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 4, sizeof( cl_mem ), (void *) & iv_stas_mem_obj );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 5, sizeof( cl_mem ), (void *) & iv_defs_mem_obj );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 6, sizeof( cl_mem ), (void *) & cpms_mem_obj );
  assert( rsl == CL_SUCCESS );
  rsl = clSetKernelArg( kernel, 7, sizeof( cl_mem ), (void *) & cps_mem_obj );
  assert( rsl == CL_SUCCESS );

  /* Execute the OpenCL Kernel on our lists */
  rsl = clEnqueueNDRangeKernel( cmd_queue,
                                kernel,
                                1,
                                NULL,
                                & global_item_size,
                                & local_item_size,
                                0,
                                NULL,
                                NULL
                              );
  assert( rsl == CL_SUCCESS );

  /* Read the Memory Buffer `c' from device to local variable `c' */
  rsl = clEnqueueReadBuffer( cmd_queue,
                             cps_mem_obj,
                             CL_TRUE,
                             0,
                             BUFFER_SIZE_CPS,
                             cps,
                             0,
                             NULL,
                             NULL
                           );
  assert( rsl == CL_SUCCESS );

  /* Print results */
  //for ( i = 0; i < LIST_SIZE_CPS; i++ )
  //  {
  //    printf( "%d\n", cps[i] );
  //  }

  /* Set exit code to match to `rsl' on failure, and free resources */
 cleanup:
  /* Set Exit Status before releasing resources wipes out CL Error Codes */
  estatus = ( rsl == CL_SUCCESS ? EXIT_SUCCESS : rsl );

  if ( cmd_queue != NULL ) rsl = clFlush( cmd_queue );
  assert( rsl == CL_SUCCESS );

  if ( cmd_queue != NULL ) rsl = clFinish( cmd_queue );
  assert( rsl == CL_SUCCESS );

  if ( kernel != NULL )    rsl = clReleaseKernel( kernel );
  assert( rsl == CL_SUCCESS );
  kernel = NULL;

  if ( program != NULL )   rsl = clReleaseProgram( program );
  program = NULL;
  assert( rsl == CL_SUCCESS );

  if ( iv_atks_mem_obj != NULL ) rsl = clReleaseMemObject( iv_atks_mem_obj );
  iv_atks_mem_obj = NULL;
  assert( rsl == CL_SUCCESS );

  if ( iv_stas_mem_obj != NULL ) rsl = clReleaseMemObject( iv_stas_mem_obj );
  iv_stas_mem_obj = NULL;
  assert( rsl == CL_SUCCESS );

  if ( iv_defs_mem_obj != NULL ) rsl = clReleaseMemObject( iv_defs_mem_obj );
  iv_defs_mem_obj = NULL;
  assert( rsl == CL_SUCCESS );

  if ( cpms_mem_obj != NULL ) rsl = clReleaseMemObject( cpms_mem_obj );
  cpms_mem_obj = NULL;
  assert( rsl == CL_SUCCESS );

  if ( cps_mem_obj != NULL ) rsl = clReleaseMemObject( cps_mem_obj );
  cps_mem_obj = NULL;
  assert( rsl == CL_SUCCESS );

  if ( cmd_queue != NULL ) rsl = clReleaseCommandQueue( cmd_queue );
  cmd_queue = NULL;
  assert( rsl == CL_SUCCESS );

  if ( context != NULL )   rsl = clReleaseContext( context );
  context = NULL;
  assert( rsl == CL_SUCCESS );

 free_mallocs:
  if ( iv_atks != NULL ) { free( iv_atks ); iv_atks = NULL; }
  if ( iv_stas != NULL ) { free( iv_stas ); iv_stas = NULL; }
  if ( iv_defs != NULL ) { free( iv_defs ); iv_defs = NULL; }
  if ( cps != NULL )     { free( cps ); cps = NULL; }
  if ( src_str != NULL ) { free( src_str ); src_str = NULL; }


  return estatus;
}
