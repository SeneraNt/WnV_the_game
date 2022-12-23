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
    Map::Init(x, y, id == 0 ? 5 : 6);
    Map& map = Map::Get();
    char key;
    NPC* npc =NULL;

    while (true)
    {
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
        cout << '\n';
        map.Move(x, y);
        npc->Battleround();
        map.clearDeadNPC();
    }

    return 0;
}