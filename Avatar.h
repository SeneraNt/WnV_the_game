#pragma once


class Ancestor {
private:
    int health;
    int healing_power;
    int id;
    int x;
    int y;

public:
    //setters
    void set_x(int xa) { x = xa; }
    void set_y(int ya) { y = ya; }
    void set_id(int x) { id = x; }
    //void set_helth() { health =2; }
    //void set_healing_power() { healing_power = 2; }
    //getters
    int get_x() { return x; }
    int get_y() { return y; }
    int get_id() { return id; }
   // int get_health() { return health; }
   // int get_healing_power() { return healing_power; }
    


};

class Vampires : Ancestor {
private:
    //int power_attack;
   // int power_defence;
public:
    Vampires(int xx, int yy)
    {
          set_x(xx); set_y(yy) ;set_id(3);
    }
    

};

class Werewolves :Ancestor {
private:
   //const int power_attack;//1-3
    //int power_defence;//1-2 den metavalontai ayta ta dyo opote 8eloyme const sunarthseis ana8eshs
public:
    Werewolves(int xx, int yy)
    {
        set_x(xx); set_y(yy); set_id(4);
    }

};

class Avatar : Ancestor {
private:
    //int num_of_magic_filters;
public:
    Avatar(int xx, int yy , int id)
    {
        set_x(xx); set_y(yy); set_id(id);
    }
    //full healing func of all members with magic filters

};