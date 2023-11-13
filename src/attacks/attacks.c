
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

u64 generate_knight_attack(int sq)
{
    u64 attack = 0ULL;

    // North-west moving
    attack |= (1ULL << north_north_west(sq)) & NOT_H_FILE & NOT_12_RANK;
    attack |= (1ULL << north_west_west(sq)) & NOT_GH_FILE & NOT_1_RANK;

    // North-east moving
    attack |= (1ULL << north_north_east(sq)) & NOT_A_FILE & NOT_12_RANK;
    attack |= (1ULL << north_east_east(sq)) & NOT_AB_FILE & NOT_1_RANK;

    // South-west moving
    attack |= (1ULL << south_west_west(sq)) & NOT_GH_FILE & NOT_8_RANK;
    attack |= (1ULL << south_south_west(sq)) & NOT_H_FILE & NOT_78_RANK;

    // South-east moving
    attack |= (1ULL << south_east_east(sq)) & NOT_AB_FILE & NOT_8_RANK;
    attack |= (1ULL << south_south_east(sq)) & NOT_A_FILE & NOT_78_RANK;

    return attack;
}

void generate_knight_attacks()
{
    for (int rank = RANK_MAX - 1; rank >= RANK_MIN; rank--)
    {
        for (int file = FILE_MIN; file < FILE_MAX; file++)
        {
            int sq = square(file, rank);
            knight_attacks[sq] = generate_knight_attack(sq);
        }
    }
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

u64 generate_king_attack(int sq)
{
    u64 attack = 0ULL;

    attack |= (1ULL << north(sq)) & NOT_1_RANK;
    attack |= (1ULL << east(sq)) & NOT_A_FILE;
    attack |= (1ULL << south(sq)) & NOT_8_RANK;
    attack |= (1ULL << west(sq)) & NOT_H_FILE;

    attack |= (1ULL << north_east(sq)) & NOT_A_FILE & NOT_1_RANK;
    attack |= (1ULL << north_west(sq)) & NOT_H_FILE & NOT_1_RANK;
    attack |= (1ULL << south_east(sq)) & NOT_A_FILE & NOT_8_RANK;
    attack |= (1ULL << south_west(sq)) & NOT_H_FILE & NOT_8_RANK;

    return attack;
}

void generate_king_attacks()
{
    for (int rank = RANK_MAX - 1; rank >= RANK_MIN; rank--)
    {
        for (int file = FILE_MIN; file < FILE_MAX; file++)
        {
            int sq = square(file, rank);
            king_attacks[sq] = generate_king_attack(sq);

            square_print(sq);
            bitboard_print(king_attacks[sq]);
        }
    }
    return;
}
