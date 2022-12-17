#include<iostream>
#include"map.h"
#include"Avatar.h"
using namespace std;



int main()
{   
    int x,y,z;
    bool exit=0;
    //Greating a map
     cout<<"Give as the size of the map please :\n";
     cout<<"Waiting for numbers of rows, x: ";
     cin>>x;
     cout<<"Waiting for numbers of columns, y: ";
     cin>>y;
     cout << endl << "Now pick a side!" << endl;
     cout << "Press 5 for team Vampires or 6 for Werewolves ~."<<endl;
          
         do {
             
             cin >> z;
             if (z == 0)
             {
                 cout << endl << "K. Bye";
                 return 0;
             }
                 
             
             if (z != 5 && z != 6)
                 cout << "WRONG INPUT " <<endl<<"Press 5 for team Vampires or 6 for Werewolves ~.Or 0 if you don't wont to play this game -.-"<<endl;

         } while (z != 5 && z != 6 );
         


     Map  my_map(x,y,z);
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
            case 'w':
                cout<<"\n\n";
                break;
            case 'a':
                cout<<" \n\n";
                break;
            case 's':
                cout<<" \n\n";
                break;
            case 'd':
                cout<<" \n\n";
                break;
            case 'p':
                //print number of remaining Vampires,Werewolfs,Num of magic filters of avatar
                cout<<" \n\n";
                break;  
            case 'x' :
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
    }
    

    return 0;

}