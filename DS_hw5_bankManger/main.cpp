//
//	main.cpp
//	ds hw5
//	SORT
//	

#include <iomanip>
#include <ctime>
#include "bankdatamanager.h"
#include "user.h"
using namespace std;

void check(vector<USER*> &b, ifstream &fans, int &correct_num, char* &in_str, char* &in_res);
BANKDATAMANAGER BDM;

int main(){
	int total_num=0, correct_num=0;
	char *in_str = new char[LENG_MAX];
	char *in_res = new char[LENG_MAX];
	vector<USER*> b1_list, b2_list, b3_list, merge_list;
	
	BDM.Parser("bank1_example");
	BDM.Parser("bank2_example");
	BDM.Parser("bank3_example");
	
	cout << "DS HW5 bank data manager" << endl;
	
	clock_t start_time, end_time;
    start_time=clock();
	//your program start here
	
	b1_list = BDM.SORTMONEY(BANK1);
	b2_list = BDM.SORTMONEY(BANK2);
	b3_list = BDM.SORTMONEY(BANK3);
	merge_list = BDM.MERGEID();
	BDM.CLEAR();
	
	// your program end here
    end_time=clock();
	
	ifstream fans("example_answer", ios::in);
	if(!fans) cout << "example_answer does not exist!!!" << endl;
	check(b1_list, fans, correct_num, in_str, in_res); total_num++;
	check(b2_list, fans, correct_num, in_str, in_res); total_num++;
	check(b3_list, fans, correct_num, in_str, in_res); total_num++;
	check(merge_list, fans, correct_num, in_str, in_res); total_num++;
	
	cout << "Correctness: " << double (100*correct_num/total_num) << "%" << endl;
    cout << "Total use " << double (end_time-start_time)/CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


void check(vector<USER*> &b, ifstream &fans, int &correct_num, char* &in_str, char* &in_res){
	int idx = 0;
	fans.getline(in_str, LENG_MAX);
	in_res = strtok(in_str, " ");
	while(in_res = strtok(NULL, " ")){
		if( idx >= b.size() ) return;
		if( b[idx]->ID != atoi(in_res) ) return;
		in_res = strtok(NULL, " ");
		if( b[idx]->money != atof(in_res) ) return;
		idx++;
	}
	if( idx != b.size() ) return;
	correct_num++;
	return;
}

