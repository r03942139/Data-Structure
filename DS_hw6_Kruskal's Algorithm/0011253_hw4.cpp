#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "time.h"
using namespace std;

struct edge {
  int a[3];
  struct edge* next;
};   //member in T,E

struct vertice {
  int  v[2];//v[0]=ver_num;v[1]=set_num;
  int  access_num; //to find start vertice
};  //vertice

int main()
{
clock_t start_time, end_time;
float total_time = 0;
start_time = clock(); /* mircosecond */

//.....................initialize E && V
struct edge* ee_root = NULL;
struct edge* ee_pre = NULL;
struct edge* ee_now = NULL;
struct edge* tt_root = NULL;
struct edge* tt_pre = NULL;
struct edge* tt_now = NULL;
int T_edge_num=0;
struct vertice* ver[100] = {NULL};
int vertice_num=0;
int set_num=0;

string File_name;
cin>>File_name; 
ifstream fin(File_name.c_str());
if(!fin)
{
   cout<<"輸入檔案無法開啟"<<endl;
   return 1; 
}
char ch;
int a_index=0;
int b_index=0;
int ver_index=0; 
char buffer[5];
memset(buffer, '\0', sizeof(buffer));
while(fin.get(ch)){
   bool already_have=false;
   if(ch=='(') {
   edge *e = new edge;
   e->next=NULL;
   if (ee_root == NULL) ee_root = e;
   else ee_now->next = e;
   ee_now=e;
   }
   else if(ch==',')  {  //put into edge and vertice,go to next number
   int i = atoi(buffer); //turn number
   ee_now->a[a_index]=i; //to a[0] or a[1]
   memset(buffer, '\0', sizeof(buffer)); //clear buffer
   b_index=0; //clear b_index
   if(a_index==0||a_index==1){  //for vertice array
     int k=0;
     for(k=0;k<100;k++){
       if(ver[k]==NULL) {already_have=false;break;} //don't have the vertice
       else if(ver[k]->v[0]==i) {already_have=true;break;}//have the vertice
     }
     if(already_have==false) { //new a vertice
       vertice *vv = new vertice;
       vv->v[0]=i;
       vv->v[1]=set_num;
       vv->access_num=0;
       ver[k]=vv;
       vertice_num++;
       set_num++;
     }
   } 
   a_index++; //next number
   }  
   else if(ch==')') {int i = atoi(buffer);
   ee_now->a[a_index]=i;
   a_index=0;
   memset(buffer, '\0', sizeof(buffer));
   b_index=0;
   }
   else {buffer[b_index]=ch;b_index++;}
}
//............................start Kruskal
while((T_edge_num<vertice_num-1)&&ee_root!=NULL){
  int low_weight=ee_root->a[2];
  edge* ee_temp=ee_root;
  ee_pre=NULL;
  for(edge* i=ee_root;i->next!=NULL;i=i->next){  //find smallest weight edge
    if((i->next)->a[2]<low_weight) {ee_pre=i;low_weight=(i->next)->a[2];ee_temp=(i->next);}
  }
  int j1=0;
  int j2=0;
  int set1=0;
  int set2=0;
  for(j1=0;j1<vertice_num;j1++) {if(ver[j1]->v[0]==ee_temp->a[0]) {set1=ver[j1]->v[1];break;}} //find set(v)
  for(j2=0;j2<vertice_num;j2++) {if(ver[j2]->v[0]==ee_temp->a[1]) {set2=ver[j2]->v[1];break;}} //find set(w)
  if(set1!=set2) {
    ver[j1]->access_num++;
    ver[j2]->access_num++;
    edge *t = new edge;
    t->a[0]= ee_temp->a[0];
    t->a[1]= ee_temp->a[1];
    t->a[2]= ee_temp->a[2];
    t->next=NULL;
    if (tt_root == NULL) tt_root = t;
    else tt_now->next = t;
    tt_now = t;
    T_edge_num++;
    for(int r=0;r<vertice_num;r++) {if(ver[r]->v[1]==set2)ver[r]->v[1]=set1;}//change set_num
  }
  if(ee_temp==ee_root) {ee_root=ee_root->next; free(ee_temp);} //delete smallest in E
  else{
    ee_pre->next=ee_temp->next;
    free(ee_temp);
  }
}
for(edge* g=tt_root;g!=NULL;g=g->next) {for(int f=0;f<3;f++) cout<<g->a[f]<<" ";cout<<endl;} //cout all edge in T

//.................path
int total_weight=0;
int start,pre_start,find_flag=0;
int stack_path[vertice_num];
int top=-1;

for(int w=0;w<vertice_num;w++) {if(ver[w]->access_num==1) {start=ver[w]->v[0];cout<<start<<" ";top++;stack_path[top]=start;break;}} //find start vertice in ver

while(tt_root!=NULL){
  int find_flag=0;
  edge* g=tt_root;
  tt_pre=NULL;
  for(g=tt_root;g!=NULL;g=g->next) { //find path in T
    if(g->a[0]==start) {cout<<g->a[1]<<" ";top++;stack_path[top]=g->a[1];start=stack_path[top];total_weight+=g->a[2];find_flag=1;break;}
    else if (g->a[1]==start) {cout<<g->a[0]<<" ";top++;stack_path[top]=g->a[0];start=stack_path[top];total_weight+=g->a[2];find_flag=1;break;}
    tt_pre=g;
   }
  if(find_flag==0){
    top--;
    start=stack_path[top];
  }
  else{    //delete edge in T
    if(g==tt_root) {tt_root=tt_root->next; free(g);} 
    else{
      tt_pre->next=g->next;
      free(g);
    }
  }
}

cout<<endl;
cout<<total_weight<<endl;

fin.close();

end_time = clock();
total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
cout<<total_time<<"ms"<<endl;
system("pause");  
}



