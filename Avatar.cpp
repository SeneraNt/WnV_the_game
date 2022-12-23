#include "Avatar.h"
#include "Random.h"
#include "map.h"

Ancestor::Ancestor(int xx, int yy)
    : x(xx), y(yy)
{
    healing_power = Random::NextInt(0, 2);
}

NPC::NPC(int xx, int yy)
    : Ancestor(xx, yy)
{
    power_attack = Random::NextInt(1, 3);
    power_defence = Random::NextInt(1, 2);
}

void NPC::Move()
{
    if (Random::NextInt(0, 4) == 0)
        return;

    const int row = Map::Get().get_num_of_row_end();
    const int col = Map::Get().get_num_of_column_end();

    std::array<int, 2> pos = TryMove();
    if (pos[0] == -2 && pos[1] == -2)//No available moves
        return;//Don't move
    while (pos[0] < 0 || pos[0] >= row || pos[1] < 0 || pos[1] >= col)
        pos = TryMove();
    x = pos[0];
    y = pos[1];
}

std::array<int, 2> Vampire::TryMove()
{
    int xx = GetX();
    int yy = GetY();

    Map& map = Map::Get();
    const int row = map.get_num_of_row_end();
    const int col = map.get_num_of_column_end();

    std::vector<std::array<int, 2>> moves;
    if (yy - 1 >= 0)
    {
        char tile = map.get_tile(xx, yy - 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2>{ xx, yy - 1 });
        if (xx - 1 >= 0)
        {
            char tile = map.get_tile(xx - 1, yy - 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx - 1, yy - 1});
        }
        if (xx + 1 < row)
        {
            char tile = map.get_tile(xx + 1, yy - 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx + 1, yy - 1});
        }
    }
    if (yy + 1 < col)
    {
        char tile = map.get_tile(xx, yy + 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx, yy + 1 });
        if (xx - 1 >= 0)
        {
            char tile = map.get_tile(xx - 1, yy + 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx - 1, yy + 1});
        }
        if (xx + 1 < row)
        {
            char tile = map.get_tile(xx + 1, yy + 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx + 1, yy + 1});
        }
    }
    if (xx - 1 >= 0)
    {
        char tile = map.get_tile(xx - 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx - 1, yy });
    }
    if (xx + 1 < row)
    {
        char tile = map.get_tile(xx + 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx + 1, yy });
    }
    
    return (moves.size() == 0 ? std::array<int, 2>{ -2, -2 } : moves[Random::NextInt(0, moves.size() - 1)]);
}

std::array<int, 2> Werewolf::TryMove()
{
    int xx = GetX();
    int yy = GetY();

    Map& map = Map::Get();
    const int row = map.get_num_of_row_end();
    const int col = map.get_num_of_column_end();

    std::vector<std::array<int, 2>> moves;
    if (xx - 1 >= 0)
    {
        char tile = map.get_tile(xx - 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx - 1, yy });
    }
    if (xx + 1 < row)
    {
        char tile = map.get_tile(xx + 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx + 1, yy });
    }
    if (yy - 1 >= 0)
    {
        char tile = map.get_tile(xx, yy - 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2>{ xx, yy - 1 });
        
    }
    if (yy + 1 < col)
    {
        char tile = map.get_tile(xx, yy + 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx, yy + 1 });
    }
    return moves.size() == 0 ? std::array<int, 2>{ -2, -2 } : moves[Random::NextInt(0, moves.size() - 1)];
}

Avatar::Avatar(int xx, int yy, int _id)
    : Ancestor(xx, yy), id(_id) {}
