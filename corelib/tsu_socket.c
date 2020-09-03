#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <memory.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "tsu_socket.h"
#include "tsu_error.h"

int start_server(int port, bool nonblocking)
{
    int sockfd;
    int opt;
    int connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        return (TSU_ERR_SOCK_CREATION_FAILED);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
        return (TSU_ERR_SOCK_SETSOCKOPT_FAILED);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if ((bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr))) != 0)
        return (TSU_ERR_SOCK_BIND_FAILED);
    if ((listen(sockfd, 5)) != 0)
        return (TSU_ERR_SOCK_LISTEN_FAILED);

    if (nonblocking)
        return (make_socket_nonblocking(sockfd));

    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0)
        return (TSU_ERR_SOCK_ACCEPT_FAILED);

    close(sockfd);
    return (TSU_ERR_SUCCESS);
}

int make_socket_nonblocking(int sockfd)
{
    int flags;

    flags = fctnl(sockfd, F_GETFL, 0);
    if (flags == -1)
        return (TSU_ERR_SOCK_MAKENONBLOCKING_GETFL_FAILED);
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1)
        return (TSU_ERR_SOCK_MAKENONBLOCKING_SETFL_FAILED);
    return (TSU_ERR_SUCCESS);
}
