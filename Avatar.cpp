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

/*#include "map.h"
#include<cstdlib> 
#include<ctime>  

using namespace std;


    const int X_BOUND = x;
    const int Y_BOUND = y; //Aytes einai oi diastaseis tou map!

class Vampires : Ancestor {
private:
    //int power_attack;
   // int power_defence;
    int num;//ari8mos tou vamps
public:
    void V_move(int x, int y) //random kinisi twn vampire
{
    int x_old = x; // apothikeuei to current x
    int y_old = y; // apothikeuei to current y

    int direction = rand() % 8;// random arithmos apo to 0-7 pou tha diksei to direction pou tha kinithei tixaia to vampir

    if (direction == 0) // Panw
    {
        y--;
    }
    else if (direction == 1) // Katw
    {
        y++;
    }
    else if (direction == 2) // Aristera
        x--;
    }
    else if (direction == 3) // Deksia
    {
        x++;
    }
    else if (direction == 4) // Panw aristera
    {
        x--;
        y--;
    }
    else if (direction == 5) // Panw deksia
    {
        x++;
        y--;
    }
    else if (direction == 6) // Katw aristera
    {
        x--;
        y++;
    }
    else if (direction == 7) // Katw deksia
    {
        x++;
        y++;
    }

    if (x < 0 || x >= X_BOUND || y < 0 || y >= Y_BOUND) // Elenxos an exei vgei ektos, an nai tote epistrofi stin proigoumenh thesh
    {
        x = x_old;
        y = y_old;
    }
}


class Werewolves :Ancestor {
private:
   //const int power_attack;//1-3
    //int power_defence;//1-2 den metavalontai ayta ta dyo opote 8eloyme const sunarthseis ana8eshs
    int count;//ari8mos synolikwn wolves
public:

    void W_move(int x, int y) //random kinisi twn werewolves panw katw deksia aristera
    
    {
        int x_old = x; // apothikeuei to current x
        int y_old = y; // apothikeuei to current y

         int direction = rand() % 4; //random arithmos gia tin kateuthinsi

        if (direction == 0) // Panw 
        {
            y--;
        }
        else if (direction == 1) // Katw
        {
            y++;
        }
        else if (direction == 2) // Aristera
        {
            x--;
        }
        else if (direction == 3) // Deksia
        {
            x++;
        }

        if (x < 0 || x >= X_BOUND || y < 0 || y >= Y_BOUND) // Elenxos an exei vgei ektos, an nai tote epistrofi stin proigoumenh thesh
        {
        x = x_old;
        y = y_old;
        }

    }
};
*/