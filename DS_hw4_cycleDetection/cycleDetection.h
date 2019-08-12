
#ifndef __DS_hw4_Cycle_Detection__
#define __DS_hw4_Cycle_Detection__

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stack>
#include "vertex.h"

using namespace std;

class Graph {
private:
    vector<Vertex*> nodeList;
    map<string,Vertex*> nMap;
public:
    void parseFile(string);
    Vertex* checkNode(string);
    bool cycleDetection();
    Graph() {}
    ~Graph() {}    
};

#endif
