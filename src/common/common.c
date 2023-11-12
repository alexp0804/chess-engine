#include "common.h"

void bitboard_print(u64 b) 
{
    for (int file = 0; file < 8; file++)
    {
        printf("  %d ", 8 - file);
        for (int rank = 0; rank < 8; rank++)
        {
            printf(" %d", bitboard_get(b, square(file, rank)) ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n     a b c d e f g h\n");
    printf("\nBitboard: %ld\n", b);
}