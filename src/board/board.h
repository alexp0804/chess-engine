#ifndef BOARD_H
#define BOARD_H

#include "../common/common.h"

enum color {
    WHITE,
    BLACK,
    NONE
};

typedef struct board {
    u64 white_pawns;
    u64 white_knights;
    u64 white_bishops;
    u64 white_rooks;
    u64 white_queens;
    u64 white_king;
    u64 black_pawns;
    u64 black_knights;
    u64 black_bishops;
    u64 black_rooks;
    u64 black_queens;
    u64 black_king;

    bool white_turn;
    i32 castling_rights;
    i32 en_passant_square;
} board;

#endif // BOARD_H
