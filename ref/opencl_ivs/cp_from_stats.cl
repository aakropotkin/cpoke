
  __kernel void
cp_from_stats(          const unsigned char    base_atk,
                        const unsigned char    base_sta,
                        const unsigned char    base_def,
               __global const unsigned char  * iv_atks,
               __global const unsigned char  * iv_stas,
               __global const unsigned char  * iv_defs,
               __global const double         * cpms,
               __global       unsigned short * cps
             )
{
  int j = get_global_id( 0 );
  int i = j % ( 16 * 16 * 16 );
  int k = j / ( 16 * 16 * 16 );
  cps[j] = max( (unsigned short) floor( 0.1 * cpms[k] * cpms[k]         *
                                        ( base_atk + iv_atks[i] )       *
                                        sqrt( (double)
                                              ( base_sta + iv_stas[i] ) *
                                              ( base_def + iv_defs[i] )
                                    )
                              ),
                (unsigned short) 10
              );
}
