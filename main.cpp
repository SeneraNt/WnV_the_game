#include<iostream>
using namespace std;



int main()
{   
    int x,y;
    bool exit=0;
    //Greating a map
     cout<<"Give us the size of the map please :\n";
     cout<<"Waiting for number of rows, x: ";
     cin>>x;
     cout<<"Waiting for number of colums, y: ";
     cin>>y;

     int **map;
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

    //Printing map
    for(int i = 0;i < x;i++) 
    {
        for(int j = 0;j < y;j++) 
        {
           cout<<map[i][j];
        }    
        cout<<endl;
    }
    

    //menu
    char key;
    cout<<"Press w to move ahead\n"
        <<"Press a to move left\n"
        <<"Press d to move right\n"
        <<"Press s to move back\n"
        <<"Press p to pause the game\n"
        <<"Press x to exit the game\n\n";

    while(!exit)
    {
        cin>>key;

        switch(key)
        {
            case 'w':
                cout<<"\n\n";
                break;
            case 'a':
                cout<<" \n\n";
                break;
            case 's':
                cout<<" \n\n";
                break;
            case 'd':
                cout<<" \n\n";
                break;
            case 'p':
                //print number of remaining Vampires,Werewolfs,Num of magic filters of avatar
                cout<<" \n\n";
                break;  
            case 'x' :
                cout<<" \n\n";
                exit=1;
                break;
            default:
                cout<<"No valid choice.\n\n"
                    <<"Press w to move ahead\n"
                    <<"Press a to move left\n"
                    <<"Press d to move right\n"
                    <<"Press s to move back\n"
                    <<"Press x to exit the game\n\n";
        }
    }
    //free the memory
    for (int i = 0; i <x; i++) 
    {
        delete[] map[i];
    }
    delete[] map;

    return 0;

}
