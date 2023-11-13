
#ifndef ATTACKS_H
#define ATTACKS_H

#include "../common/common.h"

void generate_pawn_attacks();
void generate_knight_attacks();
void generate_bishop_attacks();
void generate_rook_attacks();
void generate_queen_attacks();
void generate_king_attacks();

u64 pawn_attacks[N_SIDES][N_SQUARES];
u64 knight_attacks[N_SQUARES];
u64 bishop_attacks[N_SQUARES];
u64 rook_attacks[N_SQUARES];
u64 queen_attacks[N_SQUARES];
u64 king_attacks[N_SQUARES];

#endif // ATTACKS_H 
