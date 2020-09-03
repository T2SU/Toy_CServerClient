#ifndef TSU_ERROR_H
# define TSU_ERROR_H
# include <stdbool.h>

# define TSU_ERR_SUCCESS 0
# define TSU_ERR_SOCK_CREATION_FAILED 1
# define TSU_ERR_SOCK_BIND_FAILED 2
# define TSU_ERR_SOCK_LISTEN_FAILED 3
# define TSU_ERR_SOCK_ACCEPT_FAILED 4
# define TSU_ERR_SOCK_SETSOCKOPT_FAILED 5
# define TSU_ERR_SOCK_MAKENONBLOCKING_GETFL_FAILED 6
# define TSU_ERR_SOCK_MAKENONBLOCKING_SETFL_FAILED 7

extern char *execname;

void tsu_error(int errno, bool do_exit);

#endif
