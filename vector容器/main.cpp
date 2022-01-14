#include<iostream>
#include<vector>
#include<string>
#include<algorithm>//STL提供标准遍历算法
using namespace std;
/*
容器: vector
算法: for_each
迭代器: vector<int>::iterator
*/
#if 0 
void myPrint(int val)
{
	cout << val << " ";

}
void test01()
{
	vector<int> v;
	//放数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//vector<int>::iterator 拿到vector<int>容器的迭代器类型
	vector<int>::iterator pBegin = v.begin();//第一个数据
	vector<int>::iterator pEnd = v.end();//末位数据的下一位
	//遍历
	//1 
	while (pBegin!=pEnd)
	{

		cout << *pBegin << " ";
		pBegin++;
	}
	cout << endl;
	//2. 
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//3. 
	for_each(v.begin(), v.end(), myPrint);
}
#endif

//存放自定义数据
#if 0
class Person {
	
public:
	string mName;
	int mAge;
	Person(string name,int age)
	{
		mName = name;
		mAge = age;
		
	}

};
void test02()
{
	Person p1("a", 1);
	Person p2("b", 2);
	Person p3("c", 3);
	Person p4("d", 4);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	cout << "name\tage" << endl;
	for (vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		
		cout << (*it).mName << "\t" << (*it).mAge << endl;
	}
}
#endif
//嵌套容器
void test03()
{
	vector<vector<int>> v;//arr[3][5]
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
	{
		for (vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}



int main() {

	

	test03();

	return 0;
}
