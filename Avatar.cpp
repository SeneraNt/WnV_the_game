#include "Avatar.h"
#include "Random.h"
#include "map.h"

Ancestor::Ancestor(int xx, int yy)
    : x(xx), y(yy)
{
    potions = Random::NextInt(0, 2);
}

NPC::NPC(int xx, int yy)
    : Ancestor(xx, yy)
{
    power_attack = Random::NextInt(1, 3);
    power_defence = Random::NextInt(1, 2);
}

void NPC::BattleRound()
{
    vector<NPC*>npcs = Map::Get().getNPC();

    int attackingNpcX = GetX();
    int attackingNpcY = GetY();
    int attackingNpcAttack = power_attack;
    int attackingNpcType = GetID();

    for (NPC* defendingNpc : npcs){
        if (defendingNpc->isDead())
            continue;
        int defendingNpcX = defendingNpc->GetX();
        int defendingNpcY = defendingNpc->GetY();
        int defendingNpcType = defendingNpc->GetID();

        int defendingNpcAttack = defendingNpc->power_attack;
        int defendingNpcDeffence = defendingNpc->power_defence;

        bool adjustmentFlag = false;
        // Check If the Attacking and Deffending NPCs refere to Difference NPCs
        //if (attackingNpcX != defendingNpcX && attackingNpcY != defendingNpcY){
            if ((abs(attackingNpcX - defendingNpcX) == 1) && (attackingNpcY == defendingNpcY ) ){
                adjustmentFlag = true;
            }

            if ((abs(attackingNpcY - defendingNpcY) == 1) && (attackingNpcX == defendingNpcX) ){
                adjustmentFlag = true;
            }
        // }

        if (adjustmentFlag && attackingNpcType != defendingNpcType)
        {
            if (attackingNpcAttack > defendingNpcAttack)
                defendingNpc->SetHealth(defendingNpc->GetHealth() - (attackingNpcAttack-defendingNpcDeffence));
        }
        else if (adjustmentFlag)
        {
            int potions = GetPotions();
            if( potions > 0)
            {
                if (defendingNpc->GetHealth() < 3)
                {
                    defendingNpc->Heal();
                    SetPotions(potions - 1);
                }
            }
        }
    }
}

void Avatar::BattleRound()
{
    if (!shouldHeal || GetPotions() <= 0)
        return;

    Map& map = Map::Get();
    if ((GetID() == 5 && map.IsNight()) || (GetID() == 6 && map.IsDay()))
        return;

    std::vector<NPC*> npcs = map.getNPC();
    for (NPC* npc : npcs)
    {
        if ((npc->GetID() == 3 && GetID() == 6) || (npc->GetID() == 4 && GetID() == 5))
            continue;
        npc->Heal();
    }

    SetPotions(GetPotions() - 1);
    shouldHeal = false;
}

void NPC::Move()
{
    if (Random::NextInt(0, 4) == 0)  // 20% He won't move
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

std::array<int, 2> Vampire::TryMove() // sinartisi elenxoy kinisewn gia ta vampire poy kinounte prws oles tis kateuthinseis. Elenxei diathesimes kiniseis! exei 2 times tipoy int
{
    int xx = GetX();//sintetagmenes 
    int yy = GetY();//tou vampire

    Map& map = Map::Get();// instance toy map
    const int row = map.get_num_of_row_end();//max grami
    const int col = map.get_num_of_column_end();//max stili

    std::vector<std::array<int, 2>> moves;
    if (yy - 1 >= 0)// elenxos gia kinisi aristera
    {
        char tile = map.get_tile(xx, yy - 1);
        if ( tile == '_' || tile == '&') //borei na kinithei mono se '_' eleuthera tiles kai panw sto potion '&'
            moves.emplace_back(std::array<int, 2>{ xx, yy - 1 });
        if (xx - 1 >= 0)// einai out of bounds aristera panw
        {
            char tile = map.get_tile(xx - 1, yy - 1);
            if (tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx - 1, yy - 1});
        }
        if (xx + 1 < row)// einai out of bounds aristera katw
        {
            char tile = map.get_tile(xx + 1, yy - 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx + 1, yy - 1});
        }
    }
    if (yy + 1 < col)//elenxos gia kinisi deksia
    {
        char tile = map.get_tile(xx, yy + 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx, yy + 1 });
        if (xx - 1 >= 0)//einai out of bounds deksia panw
        {
            char tile = map.get_tile(xx - 1, yy + 1);
            if ( tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx - 1, yy + 1});
        }
        if (xx + 1 < row)//einai out of bounds deksia katw
        {
            char tile = map.get_tile(xx + 1, yy + 1);
            if (tile == '_' || tile == '&')
                moves.emplace_back(std::array<int, 2> { xx + 1, yy + 1});
        }
    }
    if (xx - 1 >= 0)//elenxos gia kinisi pros ta panw
    {
        char tile = map.get_tile(xx - 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx - 1, yy });
    }
    if (xx + 1 < row)//elenxos gia kinisi pros ta katw
    {
        char tile = map.get_tile(xx + 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx + 1, yy });
    }

    return moves.size() == 0 ? std::array<int, 2>{ -2, -2 } : moves[Random::NextInt(0, moves.size() - 1)]; // an den vrei diathesimi kinisi epistrefei -2,-2 (akiri timi)
}

std::array<int, 2> Werewolf::TryMove() // sinartisi elenxou kinisis twn werewolves kinounte mono se stavro
{
    int xx = GetX();
    int yy = GetY();

    Map& map = Map::Get();
    const int row = map.get_num_of_row_end();
    const int col = map.get_num_of_column_end();

    std::vector<std::array<int, 2>> moves;
    if (xx - 1 >= 0)//elenxos gia kinisi aristera
    {
        char tile = map.get_tile(xx - 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx - 1, yy });
    }
    if (xx + 1 < row)//elenxos gia kinisi deksia
    {
        char tile = map.get_tile(xx + 1, yy);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx + 1, yy });
    }
    if (yy - 1 >= 0)//elenxos gia kinisi pros ta panw
    {
        char tile = map.get_tile(xx, yy - 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2>{ xx, yy - 1 });

    }
    if (yy + 1 < col)//elenxos gia kinisi pros ta katw
    {
        char tile = map.get_tile(xx, yy + 1);
        if ( tile == '_' || tile == '&')
            moves.emplace_back(std::array<int, 2> { xx, yy + 1 });
    }
    return moves.size() == 0 ? std::array<int, 2>{ -2, -2 } : moves[Random::NextInt(0, moves.size() - 1)];// an den borei na kanei kinisi
}

Avatar::Avatar(int xx, int yy, int _id)
    : Ancestor(xx, yy, 0, 1), id(_id) {}

void Avatar::Move(int xx, int yy)
{
    Map& map = Map::Get(); // pernoyme to  instance toy map!
    if (xx == -1 && yy == 0)
    {
        if (GetX() - 1 < 0)
            return;
        char tile = map.get_tile(x + xx, y + yy);
        if (tile == '&')
        {
            map.set_data(x + xx, y + yy, '_');// an parei to potion eksafanizete apo ton xarti
            SetPotions(GetPotions() + 1);//auksanete o arithmos twn potion
        }
        else if (tile != '_')
            return;
        x += xx;
    }
    else if (xx == 1 && yy == 0)
    {
        if (GetX() + 1 > map.get_num_of_row_end())
            return;
        char tile = map.get_tile(x + xx, y + yy);
        if (tile == '&')
        {
            map.set_data(x + xx, y + yy, '_');// an parei to potion eksafanizete apo ton xarti
            SetPotions(GetPotions() + 1);//auksanete o arithmos twn potion
        }
        else if (tile != '_')
            return;
        x += xx;
    }
    else if (xx == 0 && yy == -1)
    {
        if (GetY() - 1 < 0)
            return;
        char tile = map.get_tile(x + xx, y + yy);
        if (tile == '&')
        {
            map.set_data(x + xx, y + yy, '_');// an parei to potion eksafanizete apo ton xarti
            SetPotions(GetPotions() + 1);//auksanete o arithmos twn potion
        }
        else if (tile != '_')
            return;
        y += yy;
    }
    else if (xx == 0 && yy == 1)
    {
        if (GetY() + 1 > map.get_num_of_column_end())
            return;
        char tile = map.get_tile(x + xx, y + yy);
        if (tile == '&')
        {
            map.set_data(x + xx, y + yy, '_');// an parei to potion eksafanizete apo ton xarti
            SetPotions(GetPotions() + 1);//auksanete o arithmos twn potion
        }
        else if (tile != '_')
            return;
        y += yy;
    }
}