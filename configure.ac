#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.70])
AC_INIT([cpoke],[0.0.1],[alex.ameen.tx@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([pcre], [pcre_compile2])
AC_CHECK_LIB([curl], [curl_easy_init])

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdint.h unistd.h curl/curl.h pcre.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([floor memmove memset pow sqrt strcasecmp strdup strncasecmp strndup])

AC_OUTPUT
