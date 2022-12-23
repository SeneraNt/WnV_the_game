#include"map.h"
//Map conctructor function
//-----------------------------------------------------------------------------//
Map::Map(int const x, int const y)
{   
    row_end=x-1;
    column_end=y-1;
    //x: num of rows
    //y:num of columns

    //Giving the start input in the vector of vectors
    for(int i=0;i<x;i++)
    {
        vector<int>row;
        for(int i=0;i<y;i++)
        {
            row.push_back(0);
        }
        
        map.push_back(row);
    }

    //Puting trees in the map (20% of map)
    int count = x * y * 0.2;
    do {

        int i = rand() % row_end;
        int j = rand() % column_end;

        if (map[i][j] == 0)
        {
            map[i][j] = 1;
            --count;
        }
    } while (count > 0);

    //puting water in map (25% of map)
    count = x * y * 0.25;
    do {

        int i = rand() % row_end;
        int j = rand() % column_end;

        if (map[i][j] == 0)
        {
            map[i][j] = 2;
            --count;
        }
    } while (count > 0);

    //putinh 1 filter on map
    count = 1;
    do {

        int i = rand() % row_end;
        int j = rand() % column_end;

        if (map[i][j] == 0)
        {
            map[i][j] = 7;
            --count;
        }
    } while (count > 0);
}
//-------------------------------------------------------------------------------------------------//
//Map output function
//-------------------------------------------------------------------------------------------------//
void Map::print_map()
{
    //-----------------------------
    for (int d = 0; d <=map.size() + 1; d++)
        cout << "=";
    cout << endl;
    //-----------------------------
    for(int i=0;i<map.size();i++)
    {
        cout << "|";
        for (int j = 0; j < map[i].size(); j++)
        {
            
            switch (map[i][j])
            {
            case 0://land
                cout << " ";
                break;
            case 1://trees
                cout << "^";
                break;
            case 2://water
                cout << "~";
                break;
            case 3://vamps
                cout << "v";
                break;
            case 4://werewolves
                cout << "w";
                break;
            case 5://player suporting vamps
                cout << "V";
                break;
            case 6: //player suporting wolves
                cout << "W";
                break;
            case 7://magic filter
                cout << "&";
                break;
            }
           
            
        }
        cout << "|";
        cout<<endl;
    }
    //----------------------------
    for (int d = 0; d <= map.size() + 1; d++)
        cout << "=";
    cout << endl;
}
//-------------------------------------------------------------------------------------------------//
//Map  get_num_of_row_end function :: returns the num of rows counting from 0.
//-------------------------------------------------------------------------------------------------//
int Map ::get_num_of_row_end() { return row_end; }
//-------------------------------------------------------------------------------------------------//
//Map  get_num_of_column_end function :: returns the num of rows counting from 0.
//-------------------------------------------------------------------------------------------------//
int Map :: get_num_of_column_end() { return column_end; }
//-------------------------------------------------------------------------------------------------//
//Map get_data function :: returns data of given coordinates 
//-------------------------------------------------------------------------------------------------//
int Map:: get_data(int x, int y){return map[x][y];}
//-------------------------------------------------------------------------------------------------//
//Map set_data function :: updates coordinates value in map and
//returns a Map class object with updated data as reference
//-------------------------------------------------------------------------------------------------//
Map& Map:: set_data(int x, int y, int value,Map &map)
   {
       int& ref = this->map[x][y];
       ref = value;
       
     
       return map;
    
   }