#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <errno.h>
#include "tsu_bytebuf.h"

bool bytebuf_seek(t_bytebuf *bytebuf, size_t pos)
{
    if (pos > bytebuf->writerindex)
    {
        errno = EINVAL;
        return (false);
    }
	bytebuf->readerindex = pos;
	return (true);
}

int8_t bytebuf_read1(t_bytebuf *bytebuf)
{
    int8_t r;

    if (bytebuf_readbuf(bytebuf, &r, sizeof(int8_t)))
        return (r);
    return (0);
}

int16_t bytebuf_read2(t_bytebuf *bytebuf)
{
    int16_t r;

    if (bytebuf_readbuf(bytebuf, &r, sizeof(int16_t)))
        return (r);
    return (0);
}

int32_t bytebuf_read4(t_bytebuf *bytebuf)
{
    int32_t r;

    if (bytebuf_readbuf(bytebuf, &r, sizeof(int32_t)))
        return (r);
    return (0);
}

int64_t bytebuf_read8(t_bytebuf *bytebuf)
{
    int64_t r;

    if (bytebuf_readbuf(bytebuf, &r, sizeof(int64_t)))
        return (r);
    return (0);
}

bool bytebuf_readbuf(t_bytebuf *bytebuf, void *dest, size_t len)
{
    size_t pos;

    pos = bytebuf->readerindex;
    if (pos + len > bytebuf->writerindex)
    {
        errno = EFAULT;
        return (false);
    }
    memcpy(dest, &bytebuf->buf[bytebuf->readerindex], len);
    bytebuf->readerindex += len;
    return (true);
}
