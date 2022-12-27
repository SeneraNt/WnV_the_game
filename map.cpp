#include"map.h"
#include "Random.h"
#include <cstring>
//Kanonika 8a eprepe na to diagrafoume kapoia stigmi
// alla 8a katastrepsi ti mnimi to leitourgiko otan stamatisi to application
// opote den mas noiazei afou 8a zei gia olo to lifetime tou application
static Map* sMap = nullptr;

void Map::Init(int x, int y, int id) { sMap = new Map(x, y, id); }
Map& Map::Get() { return *sMap; }
Map::~Map(void)
{
    delete avatar;
    for (NPC* npc : npcs)
        delete npc;
    npcs.clear();
}

Map::Map(int x, int y, int id)
{
    row_end=x-1;
    column_end=y-1;
    //x: num of rows
    //y:num of columns

    //Giving the start input in the array


    for(int i=0;i<x;i++)
    {
        vector<int>row;
        for(int i=0;i<y;i++)
        {
            row.push_back(0);
        }

        map.push_back(row);
    }

    //Puting trees in the map (20% of map)
    int count = x * y * 0.2;
    do {

        int i = Random::NextInt(0, row_end);
        int j = Random::NextInt(0, column_end);

        if (map[i][j] == 0)
        {
            map[i][j] = 1;
            --count;
        }
    } while (count > 0);

    //puting water in map (25% of map)
    count = x * y * 0.25;
    do {

        int i = Random::NextInt(0, row_end);
        int j = Random::NextInt(0, column_end);

        if (map[i][j] == 0)
        {
            map[i][j] = 2;
            --count;
        }
    } while (count > 0);

    //putinh 1 filter on map
    count = 1;
    do {

        int i = Random::NextInt(0, row_end);
        int j = Random::NextInt(0, column_end);

        if (map[i][j] == 0)
        {
            map[i][j] = 7;
            --count;
        }
    } while (count > 0);

    int num = Random::NextInt(1, x * y / 15); // tixaios arithmos sinolikwn vampires kai werewolves apo to 1 ews to x*y/15
    for (int i = 0; i < num * 2; i++) // tixaies theseis gia ta vampire kai werewolves ston xarti
    {
        int xx = Random::NextInt(0, row_end);
        int yy = Random::NextInt(0, column_end);
        char tile = get_tile(xx, yy);
        while (tile == 'v' || tile == 'w' || tile == '&') // an einai tile poy exei idi xaraktira tote psakse neo tile
        {
            xx = Random::NextInt(0, row_end);
            yy = Random::NextInt(0, column_end);
            tile = get_tile(xx, yy);
        }
        if (i % 2 == 0)
            npcs.emplace_back(new Vampire(xx, yy));
        else
            npcs.emplace_back(new Werewolf(xx, yy));
    }

    int xx = Random::NextInt(0, row_end);
    int yy = Random::NextInt(0, column_end);
    char tile = get_tile(xx, yy);

    while (tile == 'v' || tile == 'w' || tile == '&') // tixeo tile gia ton xaraktira mas an einai piasmeno psakse neo
    {
        xx = Random::NextInt(0, row_end);
        yy = Random::NextInt(0, column_end);
        tile = get_tile(xx, yy);
    }
    avatar = nullptr;
    avatar = new Avatar(xx, yy, id);
}

void Map::print_map()
{
    size_t size = (column_end + 1) * 4 + 2;//oriothetisi toy map
    char* delimeter = new char[size];
    memset(delimeter, '-', size);
    delimeter[size - 1] = '\0';
    cout << delimeter << '\n';
    for(int i=0;i<map.size();i++)
    {
        for (int j = 0; j < map[i].size() - 1; j++)
        {
            cout << "|";
            cout << ' ' << get_tile(i, j) << ' ';
        }
        cout << "| " << get_tile(i, map[i].size() - 1) << " |\n";
        cout << delimeter << '\n';
    }
}

void Map::print_stats()//koumpi "P" ektipwnei ton sinoliko arithmo twn vampires kai werewolves kai gia kathe ena posh zwh exei
{
    int werewolfs = 0, vampires = 0;
    for (NPC* npc : npcs)
    {
        if (npc->GetID() == 3 && !npc->isDead())
            vampires++;
        else if(!npc->isDead())
            werewolfs++;
    }
    cout << "Vampires: (" << vampires << ")[";
    for (NPC* npc : npcs)
    {
        if (npc->GetID() == 3)
            cout << npc->GetHealth() << ", ";
    }
    cout << "]\n";
    cout << "Werewolfs: (" << vampires << ")[";
    for (NPC* npc : npcs)
    {
        if (npc->GetID() == 4)
            cout << npc->GetHealth() << ", ";
    }
    cout << "]\n";
    cout << "Player's potions: " << avatar->GetPotions() << '\n';
}

void Map::Move(int x, int y)
{
    avatar->Move(x, y);//meta apo kinisi tou xaraktira mas kinounte ola ta zwntana NPC
    for (NPC* npc : npcs)
    {
        if (!npc->isDead())
            npc->Move();
    }
}

void Map::BattleRound(bool heal)//diadikasia maxis gia ton xaraktira mas kai gia ola ta zwntana NPC
{
    avatar->SetShouldHeal(heal);
    avatar->BattleRound();
    for (NPC* npc : npcs)
    {
        if(!npc->isDead())
            npc->BattleRound();
    }
    isDay = !isDay;
    cout << "Day: " << isDay<< "\n";
}

char Map::get_tile(int x, int y) const //epistrefei ton xaraktira poy tiponete ston xarti gia x,y
{
    int id = map[x][y];
    for (NPC* npc : npcs)
    {
        if (npc->GetHealth() > 0 && npc->GetX() == x && npc->GetY() == y)
        {
            id = npc->GetID();
            break;
        }
    }

    if (avatar != nullptr)
    {
        if (avatar->GetX() == x && avatar->GetY() == y)
            id = avatar->GetID(); 
    }

    switch (id)
    {
    case 0://land
        return '_';
    case 1://trees
        return '^';
    case 2://water
        return '~';
    case 3://vamps
        return 'v';
    case 4://werewolves
        return 'w';
    case 5://player suporting vamps
        return 'V';
    case 6: //player suporting wolves
        return 'W';
    case 7://magic filter
        return '&';
    }
}
