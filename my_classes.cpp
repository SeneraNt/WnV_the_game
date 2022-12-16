#include<my_classes.h>

class Ancestor{
    private:
        int helth;
        int healing_power;
        
    public:
        //epilegei tyxaia an 8a healarei sympexth
        void heal_func();
        //tyxaia epilogh apo 0-2
        void get_healing_power();

};

class Vampires:public Ancestor{
    private:
        int power_attack;
        int power_defence;
    public:
    //pane katw de3ia aristera kai Ddiagvnia  kata mia 8esh
    void V_move();
    //get power
    //fight fun an exe meg dyn fight win else loose health deference
    
};

class Werewolves: public Ancestor{
    private:
        int power_attack;//1-3
        int power_defence;//1-2 den metavalontai ayta ta dyo opote 8eloyme const sunarthseis ana8eshs
    public:
    //panv katw de3ia aristera kata mia 8esh
    void W_move();

};

class Avatar:  public Ancestor{
    private:
        int num_of_magic_filters;
    public:
    //full healing func of all members with magic filters

};