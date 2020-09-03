#include <tsu_bytebuf.h>
#include <munit.h>

int main(void)
{
    t_bytebuf bb;

    bytebuf_init(&bb);

    bytebuf_write1(&bb, 125);
    munit_assert(bytebuf_read1(&bb) == 125);

    bytebuf_write2(&bb, 32750);
    munit_assert(bytebuf_read2(&bb) == 32750);

    bytebuf_write4(&bb, 2137383647);
    munit_assert(bytebuf_read4(&bb) == 2137383647);

    bytebuf_write8(&bb, 93860138537235);
    munit_assert(bytebuf_read8(&bb) == 93860138537235);

    bytebuf_free(&bb);
    return (0);
}
