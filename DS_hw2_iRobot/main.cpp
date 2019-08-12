#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string.h>
#include "iRobot.h"
using namespace::std;

int main(int argc, const char * argv[])
{
    cout<<"DS HW2 iRobot"<<endl;
    iRobot example;
    char** finalMaze; 
            
    clock_t start_time,end_time;
    start_time=clock();
    
    // your program start here
    // code below is used as reference
    // it's possible check file at any time
    
    //example.buildMaze("exampleMaze.txt");
    example.buildMaze("Maze5.txt");
    finalMaze = example.findTheTrash();
    //example.printMaze();
       	  
	   
    // your program end here
    
    end_time=clock();
    cout<<"Total use "<<(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}
