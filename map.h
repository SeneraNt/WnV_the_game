#pragma once
#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
#include "Avatar.h"

using namespace std;

class Map {
private:
    vector<vector<int>> map;
    vector<NPC*> npcs;
    Avatar* avatar = nullptr;
    int row_end;
    int column_end;
    Map(int x, int y, int id);
    ~Map(void);
public:
    static void Init(int x, int y, int id);
    static Map& Get();

    void Move(int x, int y);
    void print_map();
    void print_stats();

    vector<NPC*>getNPC() { return npcs; }
    int get_num_of_row_end() const { return row_end; }
    int get_num_of_column_end() const { return column_end; }
    vector<vector<int>>& get_map() { return map; }

    void set_data(int x, int y, int value)
    {
        int count = x * y;

        int& ref = map[x][y];
        ref = value;
    }

    // https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/ Remove Dead NPCs with check isDead
    static bool isDead(NPC* npc){
        cout<< " NPC Health:"<< npc->GetHealth() << endl;

        if ( npc->GetHealth() <= 0 ){
            cout << "Remove X:"<< npc->GetX() << " Y:" << npc->GetY() << " Type:" << npc->GetID() << endl;
            return true;
        }

        return false;
    }

    void clearDeadNPC(){
        vector<NPC*>::iterator it;
        it = remove_if(npcs.begin(), npcs.end(), isDead);
        //isEven() method checks each element whether it is even or not.

        for(int i=0;i<npcs.size(); i++){
                cout << "X:"<< npcs[i]->GetX() << " Y:" << npcs[i]->GetY() << endl;
            }
    }

    int get_data(int x, int y) const { return map[x][y]; }

    char get_tile(int x, int y) const;

};