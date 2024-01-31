#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace::std;

class TDate{
public:
	void set(int m, int d, int y){
		month = m; // 不能在month前加对象名
		day = d;
		year = y;
	}

	bool isLeapYear(){
		return (((year%4 == 0) && (year%100!=0))||(year%400 == 0));
	}
	
	void print(){
		cout << month << "/" << day << "/" << year << endl;
	}
private:
	int month;
	int day;
	int year;
};

#endif
