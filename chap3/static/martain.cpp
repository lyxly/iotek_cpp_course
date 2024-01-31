#include "martain.h"

int Martain::martainCount  = 0; // 静态数据成员在类外分配空间和初始化，注释了，在链接的时候要出错

Martain::Martain(){
	martainCount++;
}
Martain::~Martain(){
	martainCount--;
}

int Martain::getCount(){
	return martainCount;
}


void Martain::fight()
{
}

void Martain::hide()
{

}

