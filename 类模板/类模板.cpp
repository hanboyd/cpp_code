#include<iostream>
#include<string>
using namespace std;
/*
类模板没有 自动类型推导 ,只能显示指定参数类型
类模板在模板参数列表中可以有默认参数
*/
#if 0

template<class T,class TT>
class Person {
public:
	T mName;
	TT mAge;
	Person(T name, TT age)
	{
		mName = name;
		mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << ", age: " << this->mAge << endl;
	}
};
int main()
{
	Person<string,int>p("aa",1);
	p.showPerson();
	cout << p.mAge << endl;

	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
	cout << P1.mAge << endl;
	
	return 0;
}
#endif // 0
/*
类模板的成员函数在调用时才创建
*/
#if 0
class Person1 {
public:
	void showPerson1()
	{
		cout<<"showPerson1()"<<endl;
	}
};
class Person2 {
public:
	void showPerson2()
	{
		cout << "showPerson2()" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;

	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};
int main()
{
	MyClass<Person1> p1;
	//p1.func2();
	p1.func1();
	return 0;
}
#endif
/*
类模板做函数参数
	1. 指定传入的类型 — 直接显示对象的数据类型
	2. 参数模板化 — 将对象中的参数变为模板进行传递
	3. 整个类模板化 — 将这个对象类型 模板化进行传递
*/
#if 0
template<class NameType,class AgeType>
class Person {
public:
	NameType mName;
	AgeType mAge;
	Person(NameType name, AgeType age); 
	void showPerson();
	
};
template<class NameType, class AgeType>
Person< NameType, AgeType>::Person(NameType name, AgeType age)
{
	mName = name;
	mAge = age;
}
template<class NameType, class AgeType>
void Person< NameType, AgeType>::showPerson()
{
	cout << "name: " << this->mName << ", age= " << this->mAge << endl;
}
//1. 指定传入的类型
void showPerson1(Person<string,int>&p)
{
	p.showPerson();
}
//2. 参数模板化
template<class T,class TT>
void showPerson2(Person<T,TT>&p)
{
	p.showPerson();
	cout << "T的类型为： " << typeid(T).name() << endl;
	cout << "TT的类型为： " << typeid(TT).name() << endl;
}
//3. 整个类模板化
template<class T>
void showPerson3(T& p)
{
	p.showPerson();
}
int main() {
	Person<string, int> p1("a", 1);
	Person<string, int> p2("b", 2);
	Person<string, int> p3("c", 3);
	showPerson1(p1);
	showPerson2(p2);
	showPerson3(p3);
	return 0;
}
#endif
/*
继承
	1. 子类继承的父类是一个模板时,子类在声明的时候,需指定父类中T的类型,否则编译器无法给子类分配内存
	2. 如要灵活指定父类T的类型,子类也需变成模板
*/
#if 0
template<class T>
class Father {
	T m;
};
//1. 指定父类中T的类型
class Son1 :public Father<int> {
};
//2. 子类变成模板
template<class T, class TT>
class Son2 :public Father<TT> {
public:
};
int main()
{
	Son1 s1;
	Son2<int,string> s2;
	return 0;
}
#endif // 0

/*
类模板份文件编写 person.h中声明和实现 改名为 person.hpp
*/
#if 0
#include"person.hpp"
int main()
{
	Person<string, int>p("a", 1);
	p.showPerson();
	return 0;
}
#endif
/*
类模板和友元
	1. 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
	2. 全局函数类内实现 - 直接在类内声明友元即可
*/
#if 0
template<class T1, class T2>class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
	cout << "2.	name: " << p.mName << ", age: " << p.mAge << endl;
}


template<class T1,class T2>
class Person {
	//1. 类内实现
	friend void printPerson1(Person<T1, T2>&p)
	{
		cout << "1.	name: " << p.mName << ", age: " << p.mAge << endl;
	}
	//2. 类外实现
	friend void printPerson2<>(Person<T1, T2>& p);
public:
	T1 mName;
	T2 mAge;
	Person(T1 name, T2 age)
	{
		this->mAge = age;
		this->mName = name;
	}
};
int main()
{
	Person<string, int>p1("a", 1);
	
	printPerson1(p1);
		printPerson2(p1);
		return 0;
}
#endif

