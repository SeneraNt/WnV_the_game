#pragma once
#include<iostream>
#include<vector>

using namespace std;

//Kanonika 8a eprepe na to diagrafoume kapoia stigmi
// alla 8a katastrepsi ti mnimi to leitourgiko otan stamatisi to application
// opote den mas noiazei afou 8a zei gia olo to lifetime tou application



class Map {
private:
   
     vector<vector< int>> map;
     
    int row_end;
    int column_end;
public:
    Map(int const , int const );
    //~Map();
    void print_map();
    int get_num_of_row_end();
    int get_num_of_column_end();
    int get_data(int , int );
   Map& set_data(int , int , int ,Map& );
  
};

