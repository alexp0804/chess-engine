#include "common/common.h"
#include "attacks/attacks.h"

int main(void)
{
    generate_pawn_attacks();
    u64 bb = 0ULL;

    bitboard_print(bb);

    return 0;
}