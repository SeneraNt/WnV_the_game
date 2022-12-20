#include "Avatar.h"
#include "map.h"
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
