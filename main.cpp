#include"map.h"

int main()
{
    int x, y;// , z;
    bool exit=0;
    //Greating a map
     cout<<"Give as the size of the map please :\n";
     cout<<"Waiting for numbers of rows, x: ";
     cin>>x;
     cout<<"Waiting for numbers of columns, y: ";
     cin>>y;

     //constructing map
     Map  my_map(x,y);
     my_map.print_map();

     cout << endl << " cl_end= " << my_map.get_num_of_column_end()
         << endl << " row_end= " << my_map.get_num_of_row_end()<<endl;

     vector<vector<int >>map1 = my_map.get_map();
     cout << "dokimh " << map1[1][1]<<endl;

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