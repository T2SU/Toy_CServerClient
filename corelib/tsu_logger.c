#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "tsu_logger.h"

void tsu_log(int ll, char *format, ...)
{
    va_list arglist;

    if (ll == LL_DEBUG)
        printf("tsu_debug: ");
    if (ll == LL_INFO)
        printf("tsu_info: ");
    if (ll == LL_ERROR)
        printf("tsu_error: ");
    va_start(arglist, format);
    vprintf(format, arglist);
    va_end(arglist);
    printf("\n");
}
