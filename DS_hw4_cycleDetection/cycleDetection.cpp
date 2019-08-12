
#include "cycleDetection.h"

void Graph::parseFile(string filename) {
    ifstream fin;
    fin.open(filename.c_str(), ios::in);
    string name1, name2;
    Vertex *vptr1, *vptr2;
    while(!fin.eof()){
        fin>>name1;
        fin>>name2;
        vptr1 = checkNode(name1);
        vptr2 = checkNode(name2);
        vptr1->connectList.push_back(vptr2);
    }
    fin.close();
}

Vertex* Graph::checkNode(string name){
    Vertex* vptr;
    map<string,Vertex*>::iterator it;  
    
    it = nMap.find(name);
    if(it != nMap.end()) return (*it).second;
    
    vptr = new Vertex(name);
    nMap.insert( pair<string,Vertex*>(name,vptr));
    nodeList.push_back(vptr);
    return vptr;
}

bool Graph::cycleDetection() {  //DFS
	Vertex *temp , *cur = vptr1->connectList[0]; // starting point
	vptr1->connectList[0].flag = 1;       
	stack<Vertex*> stack;
	stack.push(cur);    
	int i=1;
	while( !stack.empty() ){
		temp = stack.top();
		stack.pop();
		int max = temp->connectList.size();
		i=1;
		while(i<max)
		{
			cur = temp->connectList[i];
			if( cur->flag==1 )   return true;  //same
			else{
				cur->flag = 1;
				i++;
			} 
			
		}
		
	}
	
    return false;
}


