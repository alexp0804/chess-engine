
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// https://en.wikipedia.org/wiki/Algebraic_notation_(chess) 
#define N_SQUARES 64
#define RANK_MIN 0
#define RANK_MAX 8
#define FILE_MIN 0
#define FILE_MAX 8

#define bit_at(sq) ((1ULL << sq))
#define square(file, rank) (file + (7 - rank) * 8)
#define rank_of(square) (7 - square / 8)
#define file_of(square) (square % 8)
void square_print(int square);
enum SQUARE {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

#define north(square) (square - 8)
#define east(square)  (square + 1)
#define south(square) (square + 8)
#define west(square)  (square - 1)
#define north_east(square) (square - 7)
#define north_west(square) (square - 9)
#define south_east(square) (square + 9)
#define south_west(square) (square + 7)

#define north_north_west(square) (square - 17)
#define north_north_east(square) (square - 15)
#define north_west_west(square) (square - 10)
#define north_east_east(square) (square - 6)
#define south_west_west(square) (square + 6)
#define south_east_east(square) (square + 10)
#define south_south_west(square) (square + 15)
#define south_south_east(square) (square + 17)

#define N_SIDES 2
#define SIDE_MIN 0
#define SIDE_MAX 2
enum SIDE {
    white, black
};

// Bitboard with every square set except squares in A file, H file, etc
#define NOT_A_FILE 18374403900871474942ULL
#define NOT_H_FILE 9187201950435737471ULL
#define NOT_AB_FILE 18229723555195321596ULL
#define NOT_GH_FILE 4557430888798830399ULL
#define NOT_1_RANK 72057594037927935ULL
#define NOT_8_RANK 18446744073709551360ULL
#define NOT_12_RANK 281474976710655ULL
#define NOT_78_RANK 18446744073709486080ULL
#define NOT_BORDER (NOT_A_FILE & NOT_H_FILE & NOT_1_RANK & NOT_8_RANK)


#define bitboard_set(bitboard, square) (bitboard |= (1ULL << square))
#define bitboard_get(bitboard, square) (bitboard & (1ULL << square))
#define bitboard_clr(bitboard, square) (bitboard &= ~(1ULL << square))
#define bitboard_tog(bitboard, square) (bitboard ^= (1ULL << square))
void bitboard_print(u64 b);

#include "../attacks/attacks.h"

#endif // COMMON_H
