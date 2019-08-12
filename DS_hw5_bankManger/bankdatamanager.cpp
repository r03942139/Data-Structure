//
//	bankdatamanager.cpp
//	ds hw5
//	SORT
//	


#include "bankdatamanager.h"


vector<USER*> &BANKDATAMANAGER::SORTMONEY(Bank bank){
	map<double,USER*> MergeMap;
	map<double,USER*>::iterator mapitr;
	int i;
	if(bank==BANK1){
		for(i=0;i<bank1_list.size();++i){
		MergeMap.insert(bank1_list[i]->money,bank1_list[i]);
		}
		bank1_list.clear();
		for( mapitr=MergeMap.begin(); mapitr!=MergeMap.end();mapitr++){
		bank1_list.push_back(mapitr->second);
		}
		return bank1_list;
	}
	else if(bank==BANK2){
		for(i=0;i<bank2_list.size();++i){
		MergeMap.insert(bank2_list[i].money,bank2_list[i]);
		}
		bank2_list.clear();
		for( mapitr=MergeMap.begin(); mapitr!=MergeMap.end();mapitr++){
		bank2_list.push_back(mapitr->second);
		}
		return bank2_list;
	}
	else{
		for(i=0;i<bank3_list.size();++i){
		MergeMap.insert(bank3_list[i].money,bank3_list[i]);
		}
		bank3_list.clear();
		for( mapitr=MergeMap.begin(); mapitr!=MergeMap.end();mapitr++){
		bank3_list.push_back(mapitr->second);
		}
		return bank3_list;
	}
}




vector<USER*>& BANKDATAMANAGER::MERGEID(){
	map<int,USER*> MergeMap;
	map<int,USER*>::iterator mapitr;
	int i;
	for(i=0;i<bank1_list.size();++i){
		MergeMap.insert(bank1_list[i]->ID,bank1_list[i]);
	}
	for(i=0;i<bank2_list.size();++i){
		MergeMap.insert(bank2_list[i].ID,bank2_list[i]);
	}
	for(i=0;i<bank3_list.size();++i){
		MergeMap.insert(bank3_list[i].ID,bank3_list[i]);
	}
	
	for( mapitr=MergeMap.begin(); mapitr!=MergeMap.end();mapitr++){
		merge_list.push_back(mapitr->second);
	}
	
	return merge_list;
}




void BANKDATAMANAGER::CLEAR(){
	bank1_list.clear();
	bank2_list.clear();
	bank3_list.clear();
	merge_list.clear();
}



void BANKDATAMANAGER::Parser(const char* name){
	char *in_str = new char[20]; 
	char *in_res = new char[20];
	strncpy(in_str, name, 5);
	in_str[5]='\0';
	if( !strcmp(in_str, "bank1") ){ ParseBank(bank1_list, name, in_str, in_res); }
	else if( !strcmp(in_str, "bank2") ){ ParseBank(bank2_list, name, in_str, in_res); }
	else { ParseBank(bank3_list, name, in_str, in_res); }
}

void BANKDATAMANAGER::ParseBank(vector<USER*> &bank_list, const char* name, char* &in_str, char* &in_res){
	ifstream fin(name, ios::in);
	if(!fin) cout << name << " does not exist!!!!!!!!" << endl;
	while(fin.getline(in_str, LENG_MAX)){
		user = new USER();
		in_res = strtok(in_str, " ");
		user->ID = atoi(in_res);
		in_res = strtok(NULL, " ");
		user->money = atof(in_res);
		bank_list.push_back(user);
	}
	fin.close();
}
