#pragma once
#include "ancestor.h"



class Avatar: public Ancestor /*:public Ancestor */ {
private:
    int id;
    int x;
    int y;
    int num_of_magic_filters;
public:
    
    void set_num_of_magic_filters(int &magic_fil, int a=0) { magic_fil = ++a ; }
    
    Avatar( int id_num, Map& game_map)
    {
        const int X_BOUND = game_map.get_num_of_column_end();

        const int Y_BOUND = game_map.get_num_of_row_end(); //Aytes einai oi diastaseis tou map!

        set_id(id,id_num); set_num_of_magic_filters(num_of_magic_filters);

        int my_flag = 1;
        do {

            int k = rand() % X_BOUND;
            int l = rand() % Y_BOUND;

            if (game_map.get_data(k, l) == 0)
            {
                //avatar data
                 set_x(x,k); 
                 set_y(y,l);
                
                //putting avatar id to map

                game_map = game_map.set_data(k, l, id, game_map);

                --my_flag;

            }
        } while (my_flag > 0);
        
    }
    void move(string string_name, Map& game_map)
    {
        const int X_BOUND = game_map.get_num_of_column_end();
        const int Y_BOUND = game_map.get_num_of_row_end();

        if (string_name == "ahead")
        {
            if (x>0)
            {
                int k = game_map.get_data(x-1, y);
                if (k == 0 || k==7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_x(x,x -1);//updating avatar's coordinates
                    game_map = game_map.set_data(x,y, id, game_map);//updating map for next position of avatar  
                }
                else if(k==1)//tree
                {cout << endl << "You can't go ahead,there's a tree!"<<endl; }
                else if(k==2)//water
                {
                    cout << endl << "You can't go ahead,there's water!" << endl;
                }
                else if (k == 3)//vamp
                {
                    cout << endl << "You can't go ahead,there's  ";
                    if (this->id == 5)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " vampire now. ";
                }
                else if (k == 4)//werewolve
                {
                    cout << endl << "You can't go ahead,there's  ";
                    if (this->id == 6)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " werewolve now. ";
                }
            }
            else
            {
                cout << endl << "You can't go ahead, out of map coordinates!" << endl;
            }
        }
        else if (string_name == "back")
        {
            if (x<X_BOUND)
            {
                int k = game_map.get_data(x+1, y );
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_x(x,x + 1);//updating avatar's coordinates
                    game_map = game_map.set_data(x, y, id, game_map);//updating map for next position of avatar  
                }
                else if (k == 1)//tree
                {
                    cout << endl << "You can't go back,there's a tree!" << endl;
                }
                else if (k == 2)//water
                {
                    cout << endl << "You can't go back,there's water!" << endl;
                }
                else if (k == 3)//vamp
                {
                    cout << endl << "You can't go back,there's  ";
                    if (this->id == 5)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " vampire now. ";
                }
                else if (k == 4)//werewolve
                {
                    cout << endl << "You can't go back,there's  ";
                    if (this->id == 6)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " werewolve now. ";
                }
            }
            else
            {
                cout << endl << "You can't go back, out of map coordinates!" << endl;
            }
        }
        else if (string_name == "left")
        {
            if (y > 0)
            {
                int k = game_map.get_data(x, y-1 );
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_y(y,y - 1);//updating avatar's coordinates
                    game_map = game_map.set_data(x, y, id, game_map);//updating map for next position of avatar  
                }
                else if (k == 1)//tree
                {
                    cout << endl << "You can't go left,there's a tree!" << endl;
                }
                else if (k == 2)//water
                {
                    cout << endl << "You can't go left,there's water!" << endl;
                }
                else if (k == 3)//vamp
                {
                    cout << endl << "You can't go left,there's  ";
                    if (this->id == 5)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " vampire now. ";
                }
                else if (k == 4)//werewolve
                {
                    cout << endl << "You can't go left,there's  ";
                    if (this->id == 6)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " werewolve now. ";
                }
            }
            else
            {
                cout << endl << "You can't go left, out of map coordinates!" << endl;
            }
        }
        else if (string_name == "right")
        {
            if (y< Y_BOUND)
            {
                int k = game_map.get_data(x, y+1);
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_y(y,y+1);//updating avatar's coordinates
                    game_map = game_map.set_data(x, y, id, game_map);//updating map for next position of avatar  
                }
                else if (k == 1)//tree
                {
                    cout << endl << "You can't go right,there's a tree!" << endl;
                }
                else if (k == 2)//water
                {
                    cout << endl << "You can't go right,there's water!" << endl;
                }
                else if (k == 3)//vamp
                {
                    cout << endl << "You can't go right,there's  ";
                    if (this->id == 5)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " vampire now. ";
                }
                else if (k == 4)//werewolve
                {
                    cout << endl << "You can't go right,there's  ";
                    if (this->id == 6)
                        cout << "a fellow ";
                    else
                        cout << "an opponent ";
                    cout << " werewolve now. ";
                }
            }
            else
            {
                cout << endl << "You can't go right, out of map coordinates!" << endl;
            }
        }
    }
    //full healing func of all members with magic filters

};


