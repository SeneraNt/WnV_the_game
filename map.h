#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Map {
private:
    vector<vector<int>> map;
    int row_end;
    int column_end;
public:
    Map(int const x, int const y);
    //~Map();
    void print_map();
   int get_num_of_row_end() { return row_end; }
   int get_num_of_column_end() { return column_end; }
   vector<vector<int>> get_map(){ return map; }
};