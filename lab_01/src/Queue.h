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
	void pop();
	T peek();
	int count();
	friend void swap(Queue<T>& m1, Queue<T>& m2) //function of data exchange between structures
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
		l            = m2.m_tail;
		m2.m_tail    = m1.m_tail;
		m1.m_tail    = l;


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
	T* m_Data{nullptr};
	int m_Size{0}; //number of items on the stack
	int m_MaxSize{1}; //maximum number of items on the stack
	int m_head{0}; //queue start
	int m_tail{0}; //end of queue
};

template <typename T>
Queue<T>::Queue() //constructor
{
	m_Data = new T[m_MaxSize];
};

template <typename T>
Queue <T>::~Queue() //destructor
{
	delete[] m_Data;
};

template <typename T>
void Queue<T>::display() //function that displays the elements of the queue
{
	if (m_Size == 0)
	{
		throw runtime_error("Queue is empty");
	}
	else
	{
		cout << "\nOutput elements queue:";
		for (int i = m_tail-1; i >= m_head; i--)
			cout << endl << m_Data[i];
	}
	cout << endl;
};

template <typename T>
void Queue<T>::resize(int newsize) //function allocating additional memory
{
	T* newdata = new T[newsize];
	if (m_head == 0)
	{
		for (int i = 0; i < m_Size; i++)
			newdata[i] = m_Data[i];
		delete[] m_Data;
		m_Data = newdata;
		m_MaxSize = newsize;
	}
	else if(m_head > 0)
	{
		for (int i = 1; i <= m_Size; i++)
			newdata[i-1] = m_Data[i];
		delete[] m_Data;
		m_Data = newdata;
		m_MaxSize = newsize;
		m_head--;
		m_tail--;
	}

};

template <typename T>
void Queue<T>::push(T val) //function to insert an item into the queue
{
	if (m_Size == m_MaxSize)
		resize(1 + m_MaxSize);
	m_Data[m_tail] = val;
	m_tail++;
	m_Size++;
};

template <typename T>
void Queue<T>::pop() //function to remove an item from the queue
{
	if (m_head != m_tail)
	{
		m_head++;
		m_Size--;
		resize(m_MaxSize - 1);
	}
	else
	{
		throw runtime_error("Queue is empty");
	}
	
};

template <typename T>
T Queue<T>::peek() //function that returns the top of the queue
{
	if (m_Size == 0)
	{
		throw out_of_range("Queue is empty");
	}
	else
	{
		return m_Data[m_head];
	}
};

template <typename T>
int Queue<T>::count() //function returns the number of elements in the queue
{
	return m_Size;
};

template <typename T>
void Queue<T>::reverse() //reverse queue function
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