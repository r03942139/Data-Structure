//
//  iRobot.cpp
//  DS_hw2_Tree
//
//  Created by mu szu-pang on 9/12/14.
//  Copyright (c) 2014 mu szu-pang. All rights reserved.
//

#include "iRobot.h"

    typedef struct{
        int x,y,pos; 
    }Items;

void iRobot::buildMaze(string filename){
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    fin>>mazeHeight;  
    fin>>mazeWidth;   
    maze = new char* [mazeHeight];

    for(int i=0; i<mazeHeight; ++i)
        maze[i] = new char [mazeWidth];

    for(int i=0; i<mazeHeight; ++i)
        for(int j=0; j<mazeWidth; ++j)
            fin>>maze[i][j];
}


void iRobot::printMaze(){

    for(int i=0; i<mazeHeight; ++i){
        for(int j=0; j<mazeWidth; ++j){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}

char** iRobot::findTheTrash() {
		int d, e;
        for(int i=0; i<mazeHeight; ++i){  // store the Starting point
        for(int j=0; j<mazeWidth; ++j){
            if(maze[i][j]=='S'){
				d = i , e = j;break;
			}
        }
    }

	mark = new int* [mazeHeight];
	for(int i=0; i<mazeHeight; ++i)
            mark[i] = new int [mazeWidth];

    for(int i=0; i<mazeHeight; ++i)  // Build a Mark table
        for(int j=0; j<mazeWidth; ++j){
                if(maze[i][j]=='2')
                mark[i][j]=2;
                else if(maze[i][j]=='S')
                mark[i][j]=5;  // Parameter of starting point
                else
                mark[i][j]=0; }

//////////////////////////////////////////  find the path
	struct offsets{int a,b;};
    offsets move[4];
    move[0].a= -1;move[0].b=0; // North
    move[1].a=  0;move[1].b=1; //East
    move[2].a=  1;move[2].b=0; //South
    move[3].a=  0;move[3].b=-1;//West
    
    queue<Items> que;
    Items cur,next,terminal;

    int i , pos;

	cur.x = d;  cur.y = e; cur.pos = 5; //起點
    que.push(cur);

    while( !que.empty() ){
    cur = que.front();
    pos = cur.pos; pos++;
    que.pop();
    

    
	for(i=0;i<4;++i) {
    next.x = cur.x + move[i].a;
    next.y = cur.y + move[i].b;

   if(maze[next.x][next.y]=='0' && mark[next.x][next.y]<5){   //不是障礙 也未被 marked 的點
    mark[next.x][next.y] = pos;
    next.pos = pos;	
    que.push(next);
   }

   else if(maze[next.x][next.y]=='T'){ //終點
    mark[next.x][next.y] = pos;
    terminal.x = next.x ;  terminal.y = next.y;
    terminal.pos = pos;
    break;
    }
  } //end of for
  	if(maze[next.x][next.y]=='T')
    break;
} //end of  while


	while (!que.empty())
	 que.pop();
	 
  que.push(terminal);
  while(cur.x != d || cur.y != e){

  cur = que.front();
  pos = cur.pos - 1;
  que.pop();

           for(i=0;i<4;++i) {
    next.x = cur.x + move[i].a;
    next.y = cur.y + move[i].b;
    next.pos = pos;

	if(mark[next.x][next.y] == pos && pos>5){   //不是障礙 也未被 marked 的點
	maze[next.x][next.y] = '1';
    que.push(next);
    break;
   }
	else if(pos==5)
	break;
  } //end of for
if(pos==5)
break;
} //end of  while

maze[d][e] = 'S';

	for(int i=0; i<mazeHeight; ++i)
        delete [] mark[i];
    delete[]mark;
    
    return maze;
}
