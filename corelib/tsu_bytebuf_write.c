#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include "tsu_bytebuf.h"

bool bytebuf_extend_buf(t_bytebuf *bytebuf, size_t size)
{
    char *newmem;

    if (!(newmem = malloc(size + bytebuf->max)))
        return (false);
    memset(newmem, 0, size + bytebuf->max);
    if (bytebuf->buf)
    {
        memcpy(newmem, bytebuf->buf, bytebuf->max);
        free(bytebuf->buf);
    }
    bytebuf->buf = newmem;
    bytebuf->max += size;
    return (true);
}

bool bytebuf_ensure_size(t_bytebuf *bytebuf, size_t size)
{
    size_t remaining;

    remaining = bytebuf->max - bytebuf->writerindex;
    if (remaining < size)
        if (!bytebuf_extend_buf(bytebuf, size - remaining))
            return (false);
    return (true);
}

bool bytebuf_writebuf(t_bytebuf *bytebuf, void *buf, size_t blen)
{
    if (!bytebuf_ensure_size(bytebuf, blen))
        return (false);
    memcpy(bytebuf->buf + bytebuf->writerindex, buf, blen);
    bytebuf->writerindex += blen;
    return (true);
}

bool bytebuf_write1(t_bytebuf *bytebuf, int8_t n)
{
    return (bytebuf_writebuf(bytebuf, &n, sizeof(int8_t)));
}

bool bytebuf_write2(t_bytebuf *bytebuf, int16_t n)
{
    return (bytebuf_writebuf(bytebuf, &n, sizeof(int16_t)));
}

bool bytebuf_write4(t_bytebuf *bytebuf, int32_t n)
{
    return (bytebuf_writebuf(bytebuf, &n, sizeof(int32_t)));
}

bool bytebuf_write8(t_bytebuf *bytebuf, int64_t n)
{
    return (bytebuf_writebuf(bytebuf, &n, sizeof(int64_t)));
}
