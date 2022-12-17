#pragma once

#include<iostream>


using namespace std;

class Map{
        private:
            int **map;
            int row;
            int column;
        public:
            Map(int const x , int const y,int const z);
            ~Map();
            void print_map();

};
