//
//  main.cpp
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#include <iostream>
#include "fileHandler.h"
#include <ctime>
using namespace::std;

FILE_HANDLER handler;

int main(int argc, const char * argv[])
{
    cout<<"DS HW3 File system control"<<endl;
    vector<string> compareList;
    
    compareList.push_back("Captain_Kirk");
    compareList.push_back("Enterprise");
    compareList.push_back("Commander_Spock");
    compareList.push_back("battleship");
    compareList.push_back("starTrek");
    
    for (unsigned i=0; i<compareList.size(); i++) {
        for (unsigned j=i+1; j<compareList.size(); j++) {
            if (strcmp(compareList[i].c_str(), compareList[j].c_str())>0) {
                swap(compareList[i], compareList[j]);
            }
        }
    }
    
    clock_t start_time,end_time;
    start_time=clock();
    
    bool checkPass=true;
    // your program start here
    // code below is used as reference
    // it's possible check file at any time
    handler.addFileName("Capatain_Kirk");
    handler.addFileName("Enterprise");
    handler.addFileName("Commander_Spock");
    handler.addFileName("battleship");
    handler.searchFileName("HAL");
    handler.addFileName("starTrek");
    handler.searchFileName("Clock");
    handler.searchFileName("battleship");
    handler.searchFileName("Major_Tom");
    
    vector<string> fileList;
    fileList=handler.getFileList();
    if (fileList.size()!=compareList.size()) {
        cout<<"List file: unequal size"<<endl;
        checkPass=false;
    }
    else {
        for (unsigned i=0; i<fileList.size(); i++) {
            if (strcmp(fileList[i].c_str(), compareList[i].c_str())!=0) {
                cout<<"List file: fail"<<endl;
                checkPass=false;
                break;
            }
        }
    }
    if (checkPass) {
        cout<<"List file: success"<<endl;
    }
    
    handler.searchFileName("Space_Odyssey");
    // your program end here
    
    end_time=clock();
    cout<<"Total use "<<(end_time-start_time)/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
}

