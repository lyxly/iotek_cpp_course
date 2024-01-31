#ifndef _SMART_PTR
#define _SMART_PTR
#include <stdio.h>

#define TRACE_SMPTR

#ifdef TRACE_SMPTR  // g++ -D TRACE_SMPTR ����
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
//���� C2679 �����ơ� << ��: û���ҵ����ܡ�SmartPtr<Sample>�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
// ����ͽ����� �ɽ��ܵ�ת��
	operator T*(void) { // ǿ������ת������
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
		return operator=((T*)p_); // ǿ������ת��
	}

	SmartPtr& operator=(T* p_) {
		TRACE("%s,%d\n", __func__, __LINE__);
		p_->upcount();
		p->downcount(); // ԭ�������ü���Ҫ�� 1
		p = p_;
		return *this;
	}

	SmartPtr(const SmartPtr<T> &p_) { // ��������
		TRACE("%s,%d\n", __func__, __LINE__);
		p = p_.p;
		p->upcount();
	}
private:
	T* p;
};
#endif