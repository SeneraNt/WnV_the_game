#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Avatar.h"

using namespace std;

class Map {
private:
    vector<vector<int>> map;
    vector<NPC*> npcs;
    Avatar* avatar = nullptr;
    int row_end;
    int column_end;
    bool isDay = true;
    Map(int x, int y, int id); //singleton design pattern https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
    ~Map(void);
public:
    static void Init(int x, int y, int id);
    static Map& Get();

    void Move(int x, int y);
    void BattleRound(bool heal);
    void print_map();
    void print_stats();

    bool IsDay() { return isDay; }
    bool IsNight() { return !isDay; }

    vector<NPC*>getNPC() { return npcs; }
    int get_num_of_row_end() const { return row_end; }
    int get_num_of_column_end() const { return column_end; }
    vector<vector<int>>& get_map() { return map; }

    void set_data(int x, int y, int value)// stis sintetagmenes x,y vazei to value pou tou dinoyme
    {
        int count = x * y;

        int& ref = map[x][y];
        ref = value;
    }

    int get_data(int x, int y) const { return map[x][y]; }

    char get_tile(int x, int y) const;

};