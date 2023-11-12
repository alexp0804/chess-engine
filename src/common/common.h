#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// https://en.wikipedia.org/wiki/Algebraic_notation_(chess) 
enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

#define bitboard_set(bitboard, square) (bitboard |= (1ULL << square))
#define bitboard_get(bitboard, square) (bitboard & (1ULL << square))
#define bitboard_clr(bitboard, square) (bitboard &= ~(1ULL << square))
#define bitboard_tog(bitboard, square) (bitboard ^= (1ULL << square))

#define square(file, rank) file * 8 + rank

void bitboard_print(u64 b);

#endif // COMMON_H
