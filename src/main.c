#include "common/common.h"

int main(void)
{
    u64 bb = 0ULL;

    bitboard_set(bb, a8);
    bitboard_clr(bb, a8);
    bitboard_print(bb);

    return 0;
}