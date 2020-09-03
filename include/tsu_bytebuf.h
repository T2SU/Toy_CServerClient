#ifndef TSU_BYTEBUF_H
# define TSU_BYTEBUF_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_bytebuf
{
    char *buf;
    size_t writerindex;
    size_t readerindex;
    size_t max;
} t_bytebuf;

// tsu_bytebuf_construct.c
void bytebuf_init(t_bytebuf *bytebuf);
void bytebuf_free(t_bytebuf *bytebuf);

// tsu_bytebuf_read.c
bool bytebuf_seek(t_bytebuf *bytebuf, size_t pos);
int8_t bytebuf_read1(t_bytebuf *bytebuf);
int16_t bytebuf_read2(t_bytebuf *bytebuf);
int32_t bytebuf_read4(t_bytebuf *bytebuf);
int64_t bytebuf_read8(t_bytebuf *bytebuf);
bool bytebuf_readbuf(t_bytebuf *bytebuf, void *dest, size_t len);

// tsu_bytebuf_write.c
bool bytebuf_write1(t_bytebuf *bytebuf, int8_t n);
bool bytebuf_write2(t_bytebuf *bytebuf, int16_t n);
bool bytebuf_write4(t_bytebuf *bytebuf, int32_t n);
bool bytebuf_write8(t_bytebuf *bytebuf, int64_t n);
bool bytebuf_writebuf(t_bytebuf *bytebuf, void *buf, size_t blen);

#endif
