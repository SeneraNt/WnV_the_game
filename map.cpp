#include"map.h"

Map::Map(int const x, int const y)
{
    row=x;
    colum=y;

    map = new int* [x] ; //allocation for rows
     // with the for loop we allocate memory for the colums of each row
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


    //puting waterin map (25% of map)
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
        for(int j = 0;j < colum;j++) 
        {
            switch(map[i][j])
            {
                case 0:
                    cout<<"*";
                    break;
                case 1:
                    cout<<"T";
                    break;
                case 2:
                    cout<<"~";
                    break;
                case 3:
                    cout<<"";
                    break;
                case 4:
                    cout<<"";
                    break;  
                case 5 :
                    cout<<"";
                    break;
            }
        
        }    
        cout<<endl;
    }


}