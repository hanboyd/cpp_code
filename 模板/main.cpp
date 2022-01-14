#include<iostream>
using namespace std;

#if 0
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			mySwap(arr[min], arr[i]);
		}
	}
}
template<typename T>
void showArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	char str[] = "asdfgjhgfdjjhgfsadfsghjhgf";

	int len = sizeof(arr) / sizeof(int);
	mySort(arr, len);
	showArr(arr, len);
	int ll = sizeof(str) / sizeof(char);
	mySort(str, ll);
	showArr(str, ll);
}
#endif
/*
普通函数和函数模板区别:
1. 普通函数调用时可以发生自动类型转换（隐式类型转换）
2. 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换; 如果利用显示指定类型的方式，可以发生隐式类型转换
*/
#if 0
int func1(int a, int b)
{	
	return a + b;
}
template<typename T>
T func2(T a, T b)
{	
	return a + b;
}
int main()
{
	int a = 1;
	int b = 2;
	char c = 'c';
	cout << func1(a, c) << endl;//隐式转换为int
	cout << func2<int>(a, c) << endl;//显示指定类型 ; func2(a,c)自动推导
	return 0;
}
#endif

/*
调用规则 :
	1. 函数模板和普通函数都可以实现，优先调用普通函数
	2. 通过空模板参数列表来强制调用函数模板
	3. 函数模板也可以发生重载
	4. 如果函数模板可以产生更好的匹配,优先调用函数模板
*/
void func(int a, int b)
{
	cout << "func(int a, int b)" << endl;
}
template<class T>
void func(T a, T b)
{
	cout << "func(T a, T b)" << endl;
}
template<class T>
void func(T a, T b,T c)
{
	cout << "func(T a, T b,T c)" << endl;
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 0;
	func(a, b);
	func<>(a, b);
	func(a, b, c);
	return 0;
}

