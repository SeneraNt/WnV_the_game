#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"map.h"

using namespace std;

class Ancestor {
private:
    
    int id;
    int x;
    int y;
    

public:
    
    //setters
    void set_x(int &xx , int xa) { xx = xa; }
    void set_y(int &yy ,int ya) { yy = ya; }
    void set_id(int &my_id, int const x) { my_id = x; }
    //getters
    int get_x() { return x; }
    int get_y() { return y; }
    int get_id() { return id; }
    

};