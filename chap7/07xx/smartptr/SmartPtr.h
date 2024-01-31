#ifndef _SMART_PTR
#define _SMART_PTR
#include <stdio.h>

#define TRACE_SMPTR

#ifdef TRACE_SMPTR  // g++ -D TRACE_SMPTR 控制
#define TRACE printf
#else
#define TRACE
#endif

template <typename T>
class SmartPtr
{
public:
	SmartPtr(T* p_) : p(p_)
	{
		TRACE("constructor SmartPtr\n");
		p->upcount();
	}

	~SmartPtr(void)
	{
		TRACE("deconstructor SmartPtr\n");
		p->downcount();
	}

#if 1 
//错误 C2679 二进制“ << ”: 没有找到接受“SmartPtr<Sample>”类型的右操作数的运算符(或没有可接受的转换)
// 这里就进行了 可接受的转换
	operator T*(void) { // 强制类型转换重载
		//TRACE("T*(void)\n");
		TRACE("%s,%d\n", __func__, __LINE__);
		return p;
	}
#endif

	T& operator*(void) {
		TRACE("%s,%d\n", __func__, __LINE__);
		return *p;
	}

	T* operator->(void) {
		TRACE("%s,%d\n", __func__, __LINE__);
		return p;
	}

	SmartPtr& operator=(SmartPtr<T> &p_) {
		TRACE("%s,%d\n", __func__, __LINE__);
		return operator=((T*)p_); // 强制类型转换
	}

	SmartPtr& operator=(T* p_) {
		TRACE("%s,%d\n", __func__, __LINE__);
		p_->upcount();
		p->downcount(); // 原来的引用计数要减 1
		p = p_;
		return *this;
	}

	SmartPtr(const SmartPtr<T> &p_) { // 拷贝构造
		TRACE("%s,%d\n", __func__, __LINE__);
		p = p_.p;
		p->upcount();
	}
private:
	T* p;
};
#endif