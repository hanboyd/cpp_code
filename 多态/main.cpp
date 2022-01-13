#include<iostream>
using namespace std;
#include<string>
/*
静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名 ; 静态多态的函数地址早绑定 - 编译阶段确定函数地址
动态多态: 派生类和虚函数实现运行时多态 ; 动态多态的函数地址晚绑定 - 运行阶段确定函数地址
条件: 1. 继承 2. 子类重写父类的虚函数
使用条件: 父类指针或引用指向子类对象
*/

#if 0



class Animal
{
public:
	virtual void speak()
	{
		cout << "动物叫" << endl;
	}
};
class Cat :public Animal
{
public:
	 void speak()
	{
		cout << "猫说话" << endl;
	}
};
class Dog :public Animal
{
	void speak()
	{
		cout << "狗说话" << endl;
	}
};
void DoSpeak(Animal& animal)
{
	animal.speak();
}
void test01()
{
	Cat cat;
	Dog dog;
	DoSpeak(cat);
	DoSpeak(dog);
}
#endif // 0
#if 0
class Calculate {
public:
	int m_Num1;
	int m_Num2;
	virtual int getResult()
	{
		return 0;
	}
};
class AddCal :public Calculate {
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
class SubCal :public Calculate {
public:
	int getResult()
	{
		return m_Num1 -m_Num2;
	}
};
int  DoCal(Calculate& cal)
{
	return cal.getResult();

}
void test02() {
	SubCal sub;
	sub.m_Num1 = 10;
	sub.m_Num2 = 2;
	cout << DoCal(sub) << endl;
	AddCal* ad = new AddCal;
	ad->m_Num1 = 10;
	ad->m_Num2 = 3;
	cout << ad->getResult() << endl;

}

#endif // 1
/*
 抽象类: 类中有纯虚函数
 特点: 1. 不能实例化对象 2. 子类必须重写抽象类中的纯虚函数,否则也是抽象类
*/
#if 0
class Base {
public:
	virtual void func() = 0;
};
class Son:public Base
{
public:
	virtual void func() {
		cout << "func()" << endl;
	}
};
void test01() {
	Base* base = NULL;
	//base = new Base;
	base = new Son;
	base->func();
	delete base;
}


#endif // 1
/*
虚析构和纯虚析构
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
虚析构和纯虚析构共性: 1. 可以解决父类指针释放子类对象 2. 都需要有具体的函数实现
区别: 如果是纯虚析构，该类属于抽象类，无法实例化对象
*/
#if 1
class Animal
{
public:
	Animal()
	{
		cout << "Animal()" << endl;
	}
	virtual ~Animal()=0;
	virtual void Speak() = 0;
};
Animal ::~Animal()
{
	cout << "~Animal()" << endl;
}
class Cat :public Animal {
public:
	string* m_Name;
	Cat(string name)
	{
		cout << "Cat()" << endl;
		m_Name = new string(name);
	}
	~Cat()
	{
		cout << "~Cat()" << endl;
		if (this->m_Name!=NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	virtual void Speak()
	{
		cout << *m_Name << " speak" << endl;
	}
};
void test01()
{
	Animal* animal = new Cat("tom");
	animal->Speak();
	delete animal;
	Cat cat("j");
	cat.Speak();

}
#endif // 1

int main()
{
	test01();
	return 0;

}