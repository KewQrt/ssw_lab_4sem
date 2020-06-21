#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	void resize(int newsize);
	void push(T);
	void display();
	void reverse();
	T pop();
	T peek();
	int count();
	friend void swap(Queue<T>& m1, Queue<T>& m2) //обмен данными между структурами;
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
		l            = m1.m_MaxSize;
		m1.m_MaxSize = m2.m_MaxSize;
		m2.m_MaxSize = l;
		l            = m2.tail;
		m2.tail      = m1.tail;
		m1.tail      = l;


	};

	bool operator == (Queue<T>& m)
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

	bool operator > (Queue<T>& m)
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
			if (m_Data[i] < m.m_Data[i])
				return false;
			if (m_Data[i] > m.m_Data[i])
				return true;
			i++;
		}
		return m_Size > m.m_Size;
	};

	bool operator < (Queue<T>& m)
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

	bool operator != (Queue<T>& m)
	{
		return !(*this == m);
	};

	bool operator >= (Queue<T>& m)
	{
		return !(*this < m);
	};

	bool operator <= (Queue<T>& m)
	{
		return !(*this > m);
	};

private:
	T* m_Data;
	int m_Size; //кол-во элементов в стеке
	int m_MaxSize; //максимальное кол-во элементов в стеке
	int m_head; //начало очереди
	int m_tail; //конец очереди
};

template <typename T>
Queue<T>::Queue() //конструктор
{
	m_Size    = 0;
	m_MaxSize = 1;
	m_head    = 0;
	m_tail    = 0;
	m_Data    = new T[m_MaxSize];
};

template <typename T>
Queue <T>::~Queue() //деструктор
{
	delete[] m_Data;
};

template <typename T>
void Queue<T>::display() //функция выводящая элементы очереди
{
	cout << "Output elements queue" << endl;
	for (int i = m_tail - 1; i >= m_head; i--)
		cout << endl << m_Data[i];
};

template <typename T>
void Queue<T>::resize(int newsize) //функция выделяющая дополнительную память 
{
	T* newdata = new T[newsize];
	for (int i = 0; i < m_Size; ++i)
		newdata[i] = m_Data[i];
	delete[] m_Data;
	m_Data    = newdata;
	m_MaxSize = newsize;
};

template <typename T>
void Queue<T>::push(T val) //функция вставки элемента в очередеь
{
	if (m_Size == m_MaxSize)
		resize(1 + m_MaxSize);
	m_Data[m_tail] = val;
	m_tail++;
	m_Size++;
};

template <typename T>
T Queue<T>::pop() //функция удаления элемента из очереди
{
	if (m_head != m_tail)
	{
		m_head++;
		return m_Data[m_head - 1];
	}
	else
	{
		throw runtime_error("Vector is empty");
	}
	if (m_Size > 0 && m_Size < m_MaxSize - 1)
		resize(m_MaxSize - 1);
};

template <typename T>
T Queue<T>::peek() //функция возвращающая вершину очереди
{
	if (m_Size == 0)
	{
		throw out_of_range("Vector is empty");
	}
	else
	{
		return m_Data[m_head];
	}
};

template <typename T>
int Queue<T>::count() //функция возвращающая кол-во элементов в очереди
{

	return m_Size;

};

template <typename T>
void Queue<T>::reverse() //функция реверсирующая очередь
{
	if (m_Size > 0)
	{
		for (int i = 0, j = m_Size - 1; i < j; i++, j--)
		{
			T buf     = m_Data[i];
			m_Data[i] = m_Data[j];
			m_Data[j] = buf;
		}
	}
};


#endif //QUEUE_H