#pragma once
#include<iostream>
#include<vector>
#include "Avatar.h"

using namespace std;

class Map {
private:
    vector<vector<int>> map;
    vector<NPC*> npcs;
    int row_end;
    int column_end;
    Map(int x, int y);
public:
    static void Init(int x, int y);
    static Map& Get();

    void Move();
    void print_map();
    int get_num_of_row_end() const { return row_end; }
    int get_num_of_column_end() const { return column_end; }
    vector<vector<int>>& get_map() { return map; }
    
    void set_data(int x, int y, int value) 
    {
        int count = x * y;
    
        int& ref = map[x][y];
        ref = value;
    }

    int get_data(int x, int y) const { return map[x][y]; }

    char get_tile(int x, int y) const;
  
};