#pragma once

#include<iostream>
using namespace std;

class Map{
    private:
        int **map;
        int row;
        int colum;
        public:
            Map(int const x , int const y);
            ~Map();
            void print_map();
};
