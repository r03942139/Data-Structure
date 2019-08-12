//
//  fileHandler.h
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#ifndef __DS_hw3_Tree__fileHandler__
#define __DS_hw3_Tree__fileHandler__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	string data;
};

class FILE_HANDLER {
private:
	TreeNode* root;
	vector<string> v;
    
public:
	FILE_HANDLER(){ root = NULL; };
    bool Find(TreeNode*, string);
    void inorder(TreeNode*);
    //Demanded by TA   
    void addFileName(string);
    bool searchFileName(string);
    vector<string> getFileList();  // Inorder
};

#endif /* defined(__DS_hw3_Tree__fileHandler__) */
