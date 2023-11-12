#include "common.h"

void square_print(int square)
{
    printf("Square #%d: %c%d\n",
        square,
        file_of(square) + 'a',
        rank_of(square) + 1);
}

void bitboard_print(u64 b) 
{
    for (int rank = RANK_MAX - 1; rank >= RANK_MIN; rank--)
    {
        printf("  %d ", rank + 1);

        for (int file = FILE_MIN; file < FILE_MAX; file++)
        {
            printf(" %d", bitboard_get(b, square(file, rank)) ? 1 : 0);
        }

        printf("\n");
    }
    printf("\n     a b c d e f g h\n");
    printf("\nBitboard: %lu ULL\n", b);
}