
#include "attacks.h"

u64 generate_pawn_attack(int side, int sq)
{
    u64 attack = 0ULL;

    if (side == white)
    {
        attack |= (1ULL << north_east(sq)) & NOT_A_FILE & NOT_1_RANK;
        attack |= (1ULL << north_west(sq)) & NOT_H_FILE & NOT_1_RANK; 
    }
    else if (side == black)
    {
        attack |= (1ULL << south_east(sq)) & NOT_A_FILE & NOT_8_RANK;
        attack |= (1ULL << south_west(sq)) & NOT_H_FILE & NOT_8_RANK;
    }

    return attack;
}

void generate_pawn_attacks()
{
    for (int side = SIDE_MIN; side < SIDE_MAX; side++)
    {
        for (int rank = RANK_MAX - 1; rank >= RANK_MIN; rank--)
        {
            for (int file = FILE_MIN; file < FILE_MAX; file++)
            {
                int sq = square(file, rank);
                pawn_attacks[side][sq] = generate_pawn_attack(side, sq);
            }
        }
    }
}

void generate_knight_attacks()
{
    return;
}

void generate_bishop_attacks()
{
    return;
}

void generate_rook_attacks()
{
    return;
}

void generate_queen_attacks()
{
    return;
}

void generate_king_attacks()
{
    return;
}
