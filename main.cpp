#include"map.h"
#include"avatar.h"
#include"vampire.h"
#include"werewolve.h"



int main()
{
    int x, y, z;
    bool exit=0;
    //Greating a map
     cout<<"Give as the size of the map please :\n";
     cout<<"Waiting for numbers of rows, x: ";
     cin>>x;
     cout<<"Waiting for numbers of columns, y: ";
     cin>>y;
     cout << endl << "Now pick a side!" << endl;
     cout << "Press 5 for team Vampires or 6 for Werewolves ~." << endl;

     do {

         cin >> z;
         if (z == 0)
         {
             cout << endl << "K. Bye";
             return 0;
         }


         if (z != 5 && z != 6)
             cout << "WRONG INPUT " << endl << "Press 5 for team Vampires or 6 for Werewolves ~.Or 0 if you don't wont to play this game -.-" << endl;

     } while (z != 5 && z != 6);

     //constructing map
     Map  my_map(x,y);

     //No of vampires and werewolves
     int max = x * y / 15;
    //constructing vampires
     Vampires vamps(max,my_map);
   //constructing werewolves
     Werewolves wolves(max, my_map);
   //constructing Player
     Avatar player(z, my_map);
     my_map.print_map();

     

     

     //menu
    char key;
    cout<<"Press w to move ahead\n"
        <<"Press a to move left\n"
        <<"Press d to move right\n"
        <<"Press s to move back\n"
        <<"Press p to pause the game\n"
        <<"Press x to exit the game\n\n";

    while(!exit)
    {
        cin>>key;

        switch(key)
        {
            case 'w'://ahead
                cout<<"\n\n";
                player.move("ahead", my_map);
                //vamps.move(vamps.vamp_count(),my_map,vamps);
                //wolves.move(wolves.wolves_count(), my_map, wolves);
                break;
            case 'a'://left
                
                cout<<" \n\n";
                player.move("left", my_map);
                //vamps.move(vamps.vamp_count(), my_map, vamps);
                //wolves.move(wolves.wolves_count(), my_map, wolves);
                break;
            case 's'://back
                cout<<" \n\n";
                player.move("back", my_map);
                //vamps.move(vamps.vamp_count(), my_map, vamps);
                //wolves.move(wolves.wolves_count(), my_map, wolves);
                break;
            case 'd'://right
                cout<<" \n\n";
                player.move("right", my_map);
                //vamps.move(vamps.vamp_count(), my_map, vamps);
                //wolves.move(wolves.wolves_count(), my_map, wolves);
                break;
            case 'p'://pause
                //print number of remaining Vampires,Werewolfs,Num of magic filters of avatar
                cout<<" \n\n";
                break;  
            case 'x' ://exit
                cout<<" \n\n";
                exit=1;
                break;
            default:
                cout<<"No valid choice.\n\n"
                    <<"Press w to move ahead\n"
                    <<"Press a to move left\n"
                    <<"Press d to move right\n"
                    <<"Press s to move back\n"
                    <<"Press x to exit the game\n\n";
        }
        my_map.print_map();
    }

    return 0;
}
