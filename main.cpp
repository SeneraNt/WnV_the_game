#include"map.h"
#include "Random.h"
#include "Avatar.h"

int main()
{
    Random::Init();
    int x, y, id;
    cout << "Give as the size of the map please :\n";
    cout << "Waiting for numbers of rows, x: ";
    cin >> x;
    cout << "Waiting for numbers of columns, y: ";
    cin >> y;
    cout << "Select sides: 0 for Vampires or 1 for Warewolves";
    cin >> id;
    Map::Init(x, y, id == 0 ? 5 : 6);//arxikopioisi to map dinoyme id analoga me pia omada ipostirizoume
    Map& map = Map::Get();//pernoyme to instance to map!
    char key;
    NPC* npc= nullptr;

    while (true)
    {
        bool heal = false;
        x = 0; y = 0;
        map.print_map();
        cout << "AWSD to move or p to show stats: ";
        cin >> key;
        cout << endl;

        if (key == 'w' || key == 'W')
            x = -1;
        else if (key == 'a' || key == 'A')
            y = -1;
        else if (key == 'd' || key == 'D')
            y = 1;
        else if (key == 's' || key == 'S')
            x = 1;
        else if (key == 'p' || key == 'P')
        {
            map.print_stats();
            continue;
        }
        else if (key == 'e' || key == 'E')
        {
            cout << "Game over \n";
            return 0;
        }
        

        cout << '\n';
        map.Move(x, y);

        if ((id == 0 && map.IsDay()) || (id == 1 && map.IsNight()))//id = 0 dilwnei oti o paiktis einai simaxos me ta vampire opote an einai mera tote borei na ta healarei, antistixa kai gia ta werewolves
        {
            while (true)
            {
                cout << "Wanna heal? (y/n): ";
                cin >> key;
                cout << '\n';
                if (key == 'y' || key == 'Y')
                {
                    map.BattleRound(true);
                    break;
                }
                else if (key != 'n' && key != 'N')
                    cout << "Only yes(y) or no(n) answer.\n";
                else
                {
                    map.BattleRound(false);
                    break;
                }
            }
        }
        else
            map.BattleRound(false);
        
    }

    return 0;
}