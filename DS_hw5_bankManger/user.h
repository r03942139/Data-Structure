//
//	user.h
//	ds hw5
//	SORT
//	

#ifndef __DS_hw5_Sort__USER__
#define __DS_hw5_Sort__USER__
using namespace std;
enum Bank { BANK1, BANK2, BANK3 };

class USER{
	public:
		USER(){}
		USER(int id_in, double money_in){ ID = id_in; money = money_in; }
		~USER(){}
		int ID;
		double money;
};


#endif
