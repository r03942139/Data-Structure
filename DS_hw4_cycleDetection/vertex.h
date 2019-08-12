#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

class Vertex{
public:
    string name;
    int flag;
    vector<Vertex*> connectList;
    Vertex(string n) { name = n; flag = 0;}
    ~Vertex() {}
};
