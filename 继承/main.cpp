#include<iostream>
using namespace std;
/*
1. 构造顺序: father -son1 father -son2
2. 访问同名成员 : 访问子类,直接访问 s.func() ; 访问父类 添加作用域 s.father::func() ; 静态同
3. 多继承: class 子类 ：继承方式 父类1 ， 继承方式 父类2...
4. 菱形继承: 
	1. 两个派生类继承同一个基类
	2. 又有某个类同时继承者两个派生类
	问题: 子类继承两份相同内容,虚继承可解决

*/
class Father
{
public:
	Father()
	{
		cout << "father" << endl;
	}
	void func()
	{
		cout << "father func()" << endl;
	}
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承
class Son1 : public Father
{
public:
	Son1()
	{
		cout << "son1" << endl;
	}
	void func()
	{	//可以访问 public protected
		m_A;
		m_B;	
		cout << " son1 func()" << endl;
	}
};
void func1()
{
	Son1 s1;
	s1.func();
	s1.Father::func();
	s1.m_A;//public
}
//保护继承
class  Son2: protected Father
{
public:
	Son2()
	{
		cout << "son2" << endl;
	}
	void func()
	{
		//可以访问 public protected
		m_A;
		m_B;
	}

};
void func2()
{
	Son2 s2;
	//s2不能访问Father
}
//私有继承
class Son3 :private Father
{
public:
	Son3()
	{
		cout << "son3" << endl;
	}
	void func()
	{
		m_A;
		m_B;
	}
};
void func3()
{
	Son3 s3;
	//s3不能访问Father
}
class SonOfSon3 :public Son3
{
public:
	void func()
	{
		//不能访问Father
	}
};

//菱形继承
class Father1
{
public:
	int m_A;
};
//继承前加virtual关键字后，变为虚继承 ; 此时公共的父类Animal称为虚基类
class Sson1:virtual public Father1{};
class Sson2 :virtual public Father1 {};
class Sson:public Sson1,public Sson2{};
int main()
{
	Sson s;
	s.Sson1::m_A = 1;
	s.Sson2::m_A = 2;
	cout << "s.Sson1::m_A=" << s.Sson1::m_A << endl;//2
	cout << "s.Sson2::m_A=" << s.Sson2::m_A << endl;//2
	cout << "s.m_A=" << s.m_A << endl;//2
	
	return 0;
}

