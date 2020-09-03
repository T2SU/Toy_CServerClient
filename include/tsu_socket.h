#ifndef TSU_SOCKET_H
# define TSU_SOCKET_H
# include <stdbool.h>

int start_server(int port, bool nonblocking);
int make_socket_nonblocking(int sockfd);

#endif
