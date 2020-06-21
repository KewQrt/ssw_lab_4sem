#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void resize(int newsize);
	void push(T);
	void display();
	void reverse();
	T pop();
	T peek();
	int count();
	friend void swap(Stack<T>& m1, Stack<T>& m2) //������� ������ ������� ����� �����������;
	{
		if (m1.m_Size == m2.m_Size)
		{
			for (int i = 0; i < m1.m_Size; i++)
			{
				T c          = m1.m_Data[i];
				m1.m_Data[i] = m2.m_Data[i];;
				m2.m_Data[i] = c;
			}
		}
		else
		{
			T* a = new T[m1.m_Size];
			for (int i = 0; i < m1.m_Size; i++)
				a[i] = m1.m_Data[i];
			delete[] m1.m_Data;
			m1.m_Data = new T[m2.m_Size];
			for (int i = 0; i < m2.m_Size; i++)
				m1.m_Data[i] = m2.m_Data[i];
			delete[] m2.m_Data;
			m2.m_Data = a;
		}
		int l;
		l            = m1.m_Size;
		m1.m_Size    = m2.m_Size;
		m2.m_Size    = l;
		l            = m2.m_MaxSize;
		m2.m_MaxSize = m1.m_MaxSize;
		m1.m_MaxSize = l;



	};

	bool operator == (Stack<T>& m)
	{
		if (m_Size != m.m_Size)
		{
			return false;
		}
		else
		{
			int i = 0;
			while (i < m_Size)
			{
				if (m_Data[i] != m.m_Data[i]) return false;
				i++;
			}
			return  true;
		}
	};

	bool operator > (Stack<T>& m)
	{
		int minimum  = 0;
		if (m_Size < m.m_Size)
			minimum  = m_Size;
		else minimum = m.m_Size;
		int i = 0;
		while (i < minimum)
		{
			if (m_Data[i] < m.m_Data[i])
			{
				return false;
			}
			else if (m_Data[i] > m.m_Data[i])
			{
				return true;
			}
			i++;
		}
		return m_Size > m.m_Size;
	};

	bool operator < (Stack<T>& m)
	{

		int minimum = 0;
		if (m_Size < m.m_Size)
		{
			minimum = m_Size;
		}
		else
		{
			minimum = m.m_Size;
		}
		int i = 0;
		while (i < minimum)
		{
			if (m_Data[i] > m.m_Data[i])
			{
				return false;
			}
			else if (m_Data[i] < m.m_Data[i])
			{
				return true;
			}
			i++;	
		}
		return m_Size < m.m_Size;
	};

	bool operator != (Stack<T>& m)
	{
		return !(*this == m);
	};

	bool operator >= (Stack<T>& m)
	{
		return !(*this < m);
	};

	bool operator <= (Stack<T>& m)
	{
		return !(*this > m);
	};

private:
	T* m_Data;
	int m_Size;    //���-�� �������� � �����
	int m_MaxSize; //������������ ���-�� ��������� � �����
};

template <typename T>
Stack<T>::Stack() //����������� 
{
	m_Size    = 0;
	m_MaxSize = 1;
	m_Data    = new T[m_MaxSize];
};

template <typename T>
Stack<T>::~Stack() //����������
{
	delete[] m_Data;
};

template <typename T>
void Stack<T>::display() //������� ��������� �������� �����
{
	if (m_Size == 0)
	{
		throw out_of_range("Vector is empty");
	}
	else
	{
		cout << "Output elements stack" << endl;
		for (int i = m_Size - 1; i >= 0; i--)
			cout << endl << m_Data[i];
	}
};

template <typename T>
void Stack<T>::resize(int newsize) //������� ���������� �������������� ������
{
	T* newdata = new T[newsize];
	for (int i = 0; i < m_Size; ++i)
		newdata[i] = m_Data[i];
	delete[] m_Data;
	m_Data    = newdata;
	m_MaxSize = newsize;
};

template <typename T>
void Stack<T>::push(T val) //������� ������� �������� � ����
{
	if (m_Size == m_MaxSize)
		resize(1 + m_MaxSize);
	m_Size++;
	m_Data[m_Size - 1] = val;
};

template <typename T>
T Stack<T>::pop() //������� �������� �������� �� �����
{
	if (m_Size == 0)
	{
		throw out_of_range("Vector is empty");
	}
	else
	{
		--m_Size;
		return m_Data[m_Size];
		if (m_Size > 0 && m_Size < m_MaxSize - 1)
			resize(m_MaxSize - 1);
	}
};

template <typename T>
T Stack<T>::peek() //������� ������������ ������� �����
{
	if (m_Size == 0)
	{
		throw out_of_range("Vecctor is empty");
	}
	else
	{
		return m_Data[m_Size - 1];
	}
};

template <typename T>
int Stack<T>::count() //������� ������������� ���-�� ��������� � �����
{
	return m_Size;
};

template <typename T>
void Stack<T>::reverse() //������� ������������� ����
{
	if (m_Size > 0) {
		for (int i = 0, j = m_Size - 1; i < j; i++, j--) {
			T buf     = m_Data[i];
			m_Data[i] = m_Data[j];
			m_Data[j] = buf;
		}
	}
};
#endif //STACK_H