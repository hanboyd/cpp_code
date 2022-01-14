#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray {
public:
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
			this->pAddress = NULL;
		}
	}
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this.pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//重载 =
	MyArray& operator=(const MyArray& myarray)
	{
		if (this->pAddress!=NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];

	}
private:
	T* pAddress;//指向存放数据的对空间
	int m_Capacity;//容量
	int m_Size;//大小
};





