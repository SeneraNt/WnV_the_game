#include"map.h"
#include"Avatar.h"

Map::Map(int const x, int const y, int const z)
{
    row=x;
    column=y;

    map = new int* [x] ; //allocation for rows
     // with the for loop we allocate memory for the columns of each row
     for(int i=0;i<x;i++)
     {
        map[i]= new int [y]; 
     }

    //Giving the start input in the array
    for(int i = 0;i < x;i++) 
    {
        for(int j = 0;j < y;j++) 
        {
           map[i][j]=0;
        }    
    }


    //Puting trees in the map (20% of map)
    int count = x*y*0.2;
    do{
        
        int i=rand()%x;
        int j=rand()%y;

        if(map[i][j]==0)
        {
            map[i][j]=1;
            --count;
        }
    }while(count>0);


    //puting water in map (25% of map)
    count = x*y*0.25;
    do{
        
        int i=rand()%x;
        int j=rand()%y;

        if(map[i][j]==0)
        {
            map[i][j]=2;
            --count;
        }
    }while(count>0);

    //placing vampires
    count = x * y / 15;
    do {

        int i = rand() % x;
        int j = rand() % y;

        if (map[i][j] == 0)
        {
            map[i][j] = 3;
            Vampires vamps(i, j);
            --count;
        }
    } while (count > 0);

    //placing wolves
    count = x * y / 15;
    do {

        int i = rand() % x;
        int j = rand() % y;

        if (map[i][j] == 0)
        {
            map[i][j] = 4;
            Werewolves wolves(i, j);
            --count;
        }
    } while (count > 0);
    
   //placing player
    count = 1;
    do {

        int i = rand() % x;
        int j = rand() % y;

        if (map[i][j] == 0)
        {
            map[i][j] = z;
            Avatar player(i,j,z);
            --count;
        }
    } while (count > 0);
}

Map::~Map()
{
    //free the memory
    for (int i = 0; i <row; i++) 
    {
        delete[] map[i];
    }
    delete[] map;
}

void Map::print_map()
{
    //Printing map
    for(int i = 0;i < row;i++) 
    {
        for(int j = 0;j < column;j++) 
        {
            switch(map[i][j])
            {
                case 0://land
                    cout<<"_";
                    break;
                case 1://trees
                    cout<<"^";
                    break;
                case 2://water
                    cout<<"~";
                    break;
                case 3://vamps
                    cout<<"v";
                    break;
                case 4://werewolves
                    cout<<"w";
                    break;  
                case 5 ://player suporting vamps
                    cout<<"|V|";
                    break;
                case 6: //player suporting wolves
                    cout << "W";
            }
        
        }    
        cout<<endl;
    }


}