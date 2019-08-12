//
//  fileHandler.cpp
//  DS_hw3_Tree
//
//  Created by lin shih-feng on 9/12/14.
//  Copyright (c) 2014 lin shih-feng. All rights reserved.
//

#include "fileHandler.h"

void FILE_HANDLER::addFileName(string d) {
    TreeNode* t = new TreeNode;
    TreeNode* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(root==NULL) 
  	root = t;
  else{
    //Note: ALL insertions are as leaf nodes
    TreeNode* curr;
    curr = root;
    // Find the Node's parent
    while(curr){
        parent = curr;
        if( strcmp(t->data.c_str(), (curr->data).c_str()) > 0) 
			curr = curr->right;
        else 
			curr = curr->left;
    }
	curr = parent;
    if(strcmp(t->data.c_str(),(curr->data).c_str())<0)
       parent->left = t;
    else
       parent->right = t;
  }
    
}
bool FILE_HANDLER::Find(TreeNode *node, string s)
{
        if(node==NULL){
            /* Element is not found */
            return false;
        }
        
		if(strcmp(s.c_str(),(node->data).c_str())>0){
                /* Search in the right sub tree. */
                return Find(node->right,s);
        }
        else if(strcmp(s.c_str(),(node->data).c_str())<0){
                /* Search in the left sub tree. */
                return Find(node->left,s);
        }
        else{
                /* Element Found */
                return true;
        }
}

bool FILE_HANDLER::searchFileName(string s) {
    return Find(root,s);
}

void FILE_HANDLER::inorder(TreeNode* p)
{
    if(p != NULL)
    {
        if(p->left) 
			inorder(p->left); // L 
        
		v.push_back(p->data);// V 
        //cout<<" "<<p->data<<" ";
		if(p->right) 
			inorder(p->right);// R
    }
    
}

vector <string> FILE_HANDLER::getFileList() {
	inorder(root);
	return v;
}
