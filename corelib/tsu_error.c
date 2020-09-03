#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tsu_error.h"
#include "tsu_logger.h"

// main에서 argv[0] 값으로 설정되어야 함.
char *execname = NULL;

// 실제 호출
void _tsu_error(char *err_detail)
{
    tsu_log(LL_ERROR, "%s: %s", execname, err_detail);
}

// 에러 메시지 출력
void tsu_error(int errno, bool do_exit)
{
    if (errno == TSU_ERR_SUCCESS)
        _tsu_error("success");
    else if (errno == TSU_ERR_SOCK_CREATION_FAILED)
        _tsu_error("socket creation failed");
    else if (errno == TSU_ERR_SOCK_BIND_FAILED)
        _tsu_error("socket bind failed");
    else if (errno == TSU_ERR_SOCK_LISTEN_FAILED)
        _tsu_error("socket listen failed");
    else if (errno == TSU_ERR_SOCK_ACCEPT_FAILED)
        _tsu_error("socket accept failed");
    else if (errno == TSU_ERR_SOCK_SETSOCKOPT_FAILED)
        _tsu_error("socket setsockopt failed");
    else if (errno == TSU_ERR_SOCK_MAKENONBLOCKING_GETFL_FAILED)
        _tsu_error("socket makenonblocking_getfl failed");
    else if (errno == TSU_ERR_SOCK_MAKENONBLOCKING_SETFL_FAILED)
        _tsu_error("socket makenonblocking_setfl failed");
    else
        _tsu_error("unknown error");
    if (do_exit && errno != TSU_ERR_SUCCESS)
        exit(errno);
}
