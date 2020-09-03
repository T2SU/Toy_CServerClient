#include <stdlib.h>
#include <stdbool.h>
#include "tsu_bytebuf.h"

void bytebuf_init(t_bytebuf *bytebuf)
{
    bytebuf->buf = NULL;
    bytebuf->max = 0;
    bytebuf->writerindex = 0;
    bytebuf->readerindex = 0;
}

void bytebuf_free(t_bytebuf *bytebuf)
{
    if (bytebuf->buf)
    {
        free(bytebuf->buf);
        bytebuf->buf = NULL;
    }
}
