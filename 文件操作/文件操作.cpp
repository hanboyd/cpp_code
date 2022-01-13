#include<iostream>
#include<fstream>

#include<string>
using namespace std;
void test01()
{
	fstream fs;
	fs.open("test.txt", ios::out);//写文件而打开
	fs << "a" << endl;
	fs.close();
}
void test02()
{
	fstream fs;
	fs.open("test.txt", ios::in);//写文件而打开
	if (!fs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	char c;
	while ((c=fs.get())!=EOF)//EOF 文件结尾
	{
		cout << c;
	}
	fs.close();
}
class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test03()
{
	ofstream ofs("a.txt", ios::out | ios::binary);

	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = { "张三"  , 18 };

	//4、写文件
	ofs.write((const char*)&p, sizeof(p));

	//5、关闭文件
	ofs.close();

}
void test04()
{
	ifstream ifs("a.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p;
	ifs.read((char*)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
	ifs.close();
}
int main() {
	test04();
	return 0;
}