#include <iostream>
using namespace::std;

#include "date.h"
using namespace::TESTDate;

void TDate::Set(int m, int d, int y)
{
	this->month = m;
	this->day = d;
	this->year = y;
}

bool TDate::IsLeapYear()
{
	return (((year%4 == 0) && (year%100!=0))||(year%400 == 0));
}

void TDate::Print() const
{
	//month = 1;
	cout << month << "/" << day << "/" << year << endl;
}

#if 0
void print(){ // error 这是普通函数，不能访问day，year
    cout<<month <<"/"<<day<<"/"<<year<<endl;
}
#endif

