#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
	void resize(int newsize);
	void push(T);
	void display();
	void reverse();
	T& at(int);
	T pop();
	T peek();
	int count();
	friend void swap(Vector<T>& m1, Vector<T>& m2)//function of data exchange between structures
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
		l = m1.m_Size;
		m1.m_Size = m2.m_Size;
		m2.m_Size = l;
		l = m2.m_MaxSize;
		m2.m_MaxSize = m1.m_MaxSize;
		m1.m_MaxSize = l;
	};

	bool operator == (Vector<T>& m)
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

	bool operator > (Vector<T>& m)
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

	bool operator < (Vector<T>& m)
	{

		int minimum = 0;
		if (m_Size < m.m_Size)
			minimum = m_Size;
		else minimum = m.m_Size;
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

	bool operator != (Vector<T>& m)
	{
		return !(*this == m);
	};

	bool operator >= (Vector<T>& m)
	{
		return !(*this < m);
	};

	bool operator <= (Vector<T>& m)
	{
		return !(*this > m);
	};

private:
	T* m_Data;
	int m_Size;    //number of items in the queue
	int m_MaxSize; //maximum number of items in the queue
};

template <typename T>
Vector<T>::Vector() //constructor
{
	m_Size    = 0;
	m_MaxSize = 1;
	m_Data    = new T[m_MaxSize];
};

template <typename T>
Vector<T>::~Vector() //destructor
{
	delete[] m_Data;
};

template <typename T>
void Vector<T>::display() //function that displays the elements of the queue
{
	if (m_Size == 0)
	{
		throw runtime_error("Vektor is empty");
	}
	else
	{
		cout << "Output elements vector" << endl;
		for (int i = m_Size - 1; i >= 0; i--)
			cout << endl << m_Data[i];
	}
};

template <typename T>
void Vector<T>::resize(int newsize) //function allocating additional memory
{
	T* newdata = new T[newsize];
	for (int i = 0; i < m_Size; ++i)
		newdata[i] = m_Data[i];
	delete[] m_Data;
	m_Data    = newdata;
	m_MaxSize = newsize;
};

template <typename T>
void Vector<T>::push(T val) //function adding an element to a vector
{
	if (m_Size == m_MaxSize)
		resize(1 + m_MaxSize);
	m_Size++;
	m_Data[m_Size - 1] = val;
};

template <typename T>
T Vector<T>::pop() //function removing an element from a vector
{
	if (m_Size == 0)
	{
		throw runtime_error("Vektor is empty");
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
T& Vector<T>::at(int i) //function allowing access to an arbitrary vector element
{
	if ((i >= 0) && (i < m_Size))
	{
		return m_Data[i];
	}
	else
	{
		throw runtime_error("Vektor is empty");
	}
};

template <typename T>
T Vector<T>::peek() //function allowing access to an arbitrary vector element
{
	if (m_Size == 0)
	{
		throw runtime_error("Vektor is empty");
	}
	else
	{
		return m_Data[m_Size - 1];
	}
};

template <typename T>
int Vector<T>::count() //function returns the number of elements in the queue

{

	return m_Size;

};

template <typename T>
void Vector<T>::reverse()// reverse vector function
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


#endif //VECTOR
