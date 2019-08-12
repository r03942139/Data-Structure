#include <iostream>
#include "cycleDetection.h"
#include <ctime>
using namespace::std;

int main(int argc, const char * argv[])
{
    cout<<"DS HW4 Cycle Detection"<<endl;
    
    Graph *gptr;
    
    clock_t start_time,end_time;
    start_time=clock();
    
    // your program start here
    // code below is used as reference
    // it's possible check file at any time
    
    int correctNum=0;
    
    Graph *example1 = new Graph; 
    example1->parseFile("example1.txt");
    if(example1->cycleDetection()==1) correctNum++;
    delete example1;
     
    Graph *example2 = new Graph;
    example2->parseFile("example2.txt");
    if(example2->cycleDetection()==0) correctNum++;
    delete example2;
    
    Graph *example3 = new Graph;
    example3->parseFile("example3.txt");
    if(example3->cycleDetection()==1) correctNum++;
    delete example3;
    
    Graph *example4 = new Graph;
    example4->parseFile("example4.txt");
    if(example4->cycleDetection()==0) correctNum++;
    delete example4;
    
    cout<<"Total pass "<<double (correctNum*100)/4<<" percentages of cases"<<endl;
    
    // your program end here
    
    end_time=clock();
    cout<<"Total use "<<(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}

