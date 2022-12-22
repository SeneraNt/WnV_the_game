#pragma once
#include <vector>
#include "Map.h"
/*
class Ancestor {
private:
    int health;
    int healing_power;
    int attack_power;
    int defence_power;
    int id;
    int x;
    int y;
    int count;

public:
    
    //setters
    void set_x(int xa) { x = xa;}
    void set_y(int ya) { y = ya; }
    void set_id(int const x) { id = x; }
    void set_helth() { health = 2; }
    void set_healing_power() { healing_power = rand() % 2; }
    void set_attack_power() { attack_power = rand() % 3 + 1; }
    void set_defence_power() { defence_power = rand() % 2 + 1; }
    //getters
    int get_x() { return x; }
    int get_y() { return y; }
    int get_id() { return id; }
    int get_health() { return health; }
    int get_healing_power() { return healing_power; }
    int get_attack_power() { return attack_power; }
    int get_defence_power() { return  defence_power; }


};
*/

class Avatar /*:public Ancestor */ {
private:
    int id;
    int x;
    int y;
    int num_of_magic_filters;
public:
    void set_x(int xa) { x = xa; }
    void set_y(int ya) { y = ya; }
    void set_id(int const x) { id = x; }
    void set_num_of_magic_filters(int a) { num_of_magic_filters = a ; }
    Avatar( int id_num, Map& game_map)
    {
        const int X_BOUND = game_map.get_num_of_column_end();

        const int Y_BOUND = game_map.get_num_of_row_end(); //Aytes einai oi diastaseis tou map!

        set_id(id_num); set_num_of_magic_filters(1);

        int my_flag = 1;
        do {

            int k = rand() % X_BOUND;
            int l = rand() % Y_BOUND;

            if (game_map.get_data(k, l) == 0)
            {
                 set_x(k); set_y(l);
                
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
            if (this->y < Y_BOUND)
            {
                int k = game_map.get_data(x+1, y);
                if (k == 0 || k==7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_x(x + 1);//updating avatar's coordinates
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
            if (this->y >0)
            {
                int k = game_map.get_data(x-1, y );
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_x(x - 1);//updating avatar's coordinates
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
            if (this->x > 0)
            {
                int k = game_map.get_data(x, y-1 );
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_y(y - 1);//updating avatar's coordinates
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
            if (this->x < X_BOUND)
            {
                int k = game_map.get_data(x, y+1);
                if (k == 0 || k == 7)//land or magic filter
                {
                    if (k == 7)
                        num_of_magic_filters++;
                    game_map = game_map.set_data(x, y, 0, game_map);//updating map for current position of avatar to land 
                    set_y(y+1);//updating avatar's coordinates
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

class Vampires  {
private:
    //----------------
    
    std::vector <int> health;
    std::vector<int> healing_power;
    std::vector<int> attack_power;
    std::vector<int> defence_power;
    std::vector<int> id;
    std::vector<int> x;
    std::vector<int> y;
    //-----------------

    int vamps_num;//ari8mos synolikwn vamps
public:
    
    //Constractor :  initialising data
    Vampires(int count, Map& game_map) {
        vamps_num = count;
        


        const int X_BOUND=game_map.get_num_of_column_end();
       
        const int Y_BOUND=game_map.get_num_of_row_end(); //Aytes einai oi diastaseis tou map!
        
    
        for (int i = 0; i < count; i++)
        {
            health.push_back(2);
            healing_power.push_back(rand() % 2);
            attack_power.push_back(rand() % 3 + 1);
            defence_power.push_back(rand() % 2 + 1);
            id.push_back(3);

            int my_flag = 1;
            do {

                int k = rand() % X_BOUND;
                int l = rand() % Y_BOUND;

                if (game_map.get_data(k,l)== 0)
                {
                    x.push_back(k);
                    y.push_back(l);
                    //putting vamp id to map
                          
                    game_map=game_map.set_data(k, l, 3,game_map);

                    --my_flag;

                }
            } while (my_flag > 0);
         }
    }
    
};
class Werewolves {
private:
    //----------------

    std::vector <int> health;
    std::vector<int> healing_power;
    std::vector<int> attack_power;
    std::vector<int> defence_power;
    std::vector<int> id;
    std::vector<int> x;
    std::vector<int> y;
    //-----------------

    int wolves_num;//ari8mos synolikwn vamps
public:

    //Constractor :  initialising data
    Werewolves(int count, Map& game_map) {
        wolves_num = count;



        const int X_BOUND = game_map.get_num_of_column_end();

        const int Y_BOUND = game_map.get_num_of_row_end(); //Aytes einai oi diastaseis tou map!


        for (int i = 0; i < count; i++)
        {
            health.push_back(2);
            healing_power.push_back(rand() % 2);
            attack_power.push_back(rand() % 3 + 1);
            defence_power.push_back(rand() % 2 + 1);
            id.push_back(3);

            int my_flag = 1;
            do {

                int k = rand() % X_BOUND;
                int l = rand() % Y_BOUND;

                if (game_map.get_data(k, l) == 0)
                {
                    x.push_back(k);
                    y.push_back(l);
                    //putting vamp id to map

                    game_map = game_map.set_data(k, l, 4, game_map);

                    --my_flag;

                }
            } while (my_flag > 0);
        }
    }

};