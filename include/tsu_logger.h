#ifndef TSU_LOGGER_H
 #define TSU_LOGGER_H

// 'L'og 'L'evel Definitions
# define LL_DEBUG 10
# define LL_INFO 5
# define LL_ERROR 3

void tsu_log(int ll, char *format, ...);

#endif
