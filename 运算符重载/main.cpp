#include<iostream>
using namespace std;
// + - ++ -- << == 
#if 0
class MyClass
{
	friend ostream& operator<<(ostream& cout, MyClass& myclass);
public:
	MyClass(int a = 10);
	~MyClass();
	// +
	MyClass operator+(const MyClass& myclass);
	// -
	MyClass operator-(const MyClass& myclass);
	// ++a
	MyClass& operator++();
	// a++
	MyClass operator++(int);
	// --a
	MyClass& operator--();
	// a--
	MyClass operator--(int);
	// ==
	bool operator==(MyClass& myclass);
	// ()
	void operator()(int)

private:
	int m_A;
};
// <<
ostream& operator<<(ostream& cout, MyClass& myclass)
{
	cout << myclass.m_A;
	return cout;
}
MyClass::MyClass(int myclass)
{
	m_A = myclass;
}

MyClass::~MyClass()
{
}
MyClass MyClass::operator+(const MyClass& myclass)
{
	MyClass temp;
	temp.m_A = this->m_A + myclass.m_A;
	return temp;
}
MyClass MyClass::operator-(const MyClass& myclass)
{
	MyClass temp;
	temp.m_A = this->m_A - myclass.m_A;
	return temp;
}
MyClass& MyClass::operator++()
{
	m_A++;
	return*this;
}
MyClass MyClass::operator++(int)
{
	MyClass temp = *this;
	m_A++;
	return temp;
}
MyClass& MyClass::operator--()
{
	m_A--;
	return*this;
}
MyClass MyClass::operator--(int)
{
	MyClass temp = *this;
	m_A--;
	return temp;
}
bool MyClass::operator==(MyClass& myclass)
{
	if (this->m_A == myclass.m_A)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	MyClass a(10), b(5), c(0), d(0);
	c = a + b;
	d = a - b;
	cout << "a = " << a << endl;
	cout << "a+b = " << c << " , a-b = " << d << endl;
	d = a++;
	cout << "a++ = " << d << endl;
	cout << "++a = " << ++a << endl;
	d = a--;
	cout << "a-- = " << d << endl;
	cout << "--a = " << --a << endl;
	if (a == b)
	{
		cout << "a = b" << endl;
	}
	else
	{
		cout << "a != b" << endl;

	}

	return 0;
}
#endif

#if 0
class MyClass
{
public:
	MyClass(int a);
	~MyClass();
	MyClass& operator = (MyClass& myclass);

	int* m_A;
};

MyClass::MyClass(int a)
{
	m_A = new int(a);////将年龄数据开辟到堆区
}

MyClass::~MyClass()
{
	if (m_A != NULL)
	{
		delete m_A;
		m_A = NULL;
	}
}
MyClass& MyClass::operator = (MyClass& myclass)
{
	if (m_A != NULL)
	{
		delete m_A;
		m_A = NULL;
	}
	m_A = new int(*myclass.m_A);//深拷贝 ;编译器默认浅拷贝: m_A=myclass.m_A;
	return *this;
}
int main()
{

	MyClass m1(10);
	MyClass m2(20);

	cout << "m1.m_A= " << *m1.m_A << endl;
	cout << "m2.m_A= " << *m2.m_A << endl;
	m2 = m1;
	cout << "m2.m_A= " << *m2.m_A << endl;
	return 0;

}
#endif

#if 1
class MyClass
{
public:
	int operator()(int a, int b)//仿函数
	{
		return a + b;
	}
};
int main()
{
	MyClass myclass;
	int ret = myclass(1, 2);
	cout << ret << endl;
	cout << MyClass()(2, 4) << endl;//匿名对象调用  
	return 0;
}

#endif