#pragma once

#include<iostream>
#include"Avatar.h"


using namespace std;

class Map{
        private:
            int **map;
             int  row;
             int  column;
            

        public:
            Map(int const x , int const y,int const z);
            ~Map();
            void print_map();
            const int get_num_of_rows();
            const int get_num_of_columns();
            int get_map_id(int x,int y);
            void set_map_id(int x, int y,int value);
};
