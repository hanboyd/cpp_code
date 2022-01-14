#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
string 本质是个类 

*/

//构造
#if 1
void test01()
{
	string s1;//默认构造
	const char* str = "hello";
	string s2(str);//c_cstring转string
	string s3(s2);//拷贝构造
	string s4('a', 10);
	cout << s4 << endl;
	string s5(10, 'a');
	//cout << s5 << endl;
}
#endif

//赋值
#if 1
void test02()
{
	string s1;
	s1 = "hello";
	cout << "s1: " << s1 << endl;

	string s2;
	s2 = s1;
	cout << "s2: " << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3: " << s3 << endl;

	string s4;
	s4.assign("hello world");//把"aaa"赋给当前字符串
	cout << "s4: " << s4 << endl;

	string s5;
	s5.assign("hello world", 5);//把"aaa"的前 5 个字符覆当前字符串
	cout << "s5: " << s5 << endl;

	string s6;
	s6.assign(s5);//把字符串覆赋给当前字符串
	cout << "s6: " << s6 << endl;

	string s7;
	s7.assign(5, 'x');//把'a' 字符复制 赋给当前字符串
	cout << "s7: " << s7 << endl;
}
#endif
//拼接
void test03()
{
	string s1 = "a";
	s1 += "b";
	cout << "s1: " << s1 << endl;
	string s2 = "c cc ccc ";
	s1 += s2;
	cout << "s1: " << s1 << endl;

	string s3 = "A";
	s3.append("BBBBBBB");
	cout << "s3: " << s3 << endl;
	s3.append("CDEFG H", 2);//截取""的前2位 拼接到s3 末位
	cout << "s3: " << s3 << endl;
	s3.append(s2, 4, 3);//从下标4开始 截取 3 个字符 拼接到 s3末位
	cout << "s3: " << s3 << endl;
}
//查找 替换
void test04()
{
	string s1 = "abcdefghijklmn";
	int pos = 0;
	pos = s1.find("bc");
	cout << pos << endl;
	pos = s1.find('c');
	cout << pos << endl;
	pos = s1.rfind("bc");
	cout << pos << endl;

	s1.replace(1, 2, "00");
	cout << s1 << endl;//a00defghijklmn
}
//比较
void test05()
{
	string s1 = "hello";
	string s2 = "olleh";
	int ret = s1.compare(s2);//比较是否相等
	cout << ret << endl;
}
//存取
void test06()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << "";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	

}
//插入 删除
void test07()
{
	string s1 = "hello";
	s1.insert(1, "1");//在 1 处插入 " " 
	cout << "s1= " << s1 << endl;
	s1.erase(2, 3);
	cout << "s1= " << s1 << endl;
}
int main()
{
	test07();
	return 0;
}