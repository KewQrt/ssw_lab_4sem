#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
#include <queue>

#include "Stack.h"
#include "Queue.h"
#include "Vector.h"

using ms = std::chrono::milliseconds;
using namespace std;

int main(int charc, char** argv)
{
	try {
		Vector <int> vector1;
		vector<int> vector2;
		Stack <int> stack1;
		stack <int> stack2;
		Queue <int> queue1;
		queue <int> queue2;

		//Vector

		cout << "\nPush element in vector\n";
		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			vector1.push(11);
		auto end = std::chrono::high_resolution_clock::now();
		auto res_time = std::chrono::duration_cast<ms>(end - start).count();
		auto start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			vector2.push_back(11);
		auto end1 = std::chrono::high_resolution_clock::now();
		auto res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My vector=" << res_time << endl;
		cout << "STL vector=" << res_time1 << endl;
		cout << "\nVector size\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			vector1.count();
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			vector2.size();
		end1 = std::chrono::high_resolution_clock::now();
		res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My vector=" << res_time1 << endl;
		cout << "STL vector=" << res_time1 << endl;
		cout << "\nAt vector:\n ";
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			vector1.at(i) = 3;
		end = chrono::high_resolution_clock::now();
		res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		start1 = chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			vector2.at(i) = 3;
		end1 = chrono::high_resolution_clock::now();
		res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
		cout << "My Stack=" << res_time << endl;
		cout << "stl stack=" << res_time1 << endl;

		//Stack

		cout << "\nPush element in stack\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			stack1.push(11);
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			stack2.push(11);
		end1 = std::chrono::high_resolution_clock::now();
		res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My stack=" << res_time << endl;
		cout << "STL stack=" << res_time1 << endl;
		cout << "\nPeek element of stack\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			stack1.peek();
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			stack2.top();
		end1 = std::chrono::high_resolution_clock::now();
		res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My stack=" << res_time << endl;
		cout << "STL stack=" << res_time1 << endl;
		cout << "\nCount stack\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			stack1.count();
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		cout << "My stack=" << res_time << endl;

		//Queue

		cout << "\nPush element in queue\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			queue1.push(11);
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
			queue2.push(11);
		end1 = std::chrono::high_resolution_clock::now();
		res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My queue=" << res_time << endl;
		cout << "STL queue=" << res_time1 << endl;
		cout << "\nPeek element of queue\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			queue1.peek();
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		start1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			queue2.front();
		end1 = std::chrono::high_resolution_clock::now();
		res_time1 = std::chrono::duration_cast<ms>(end1 - start1).count();
		cout << "My queue=" << res_time << endl;
		cout << "STL queue=" << res_time1 << endl;
		cout << "\nCount queue\n";
		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000000; i++)
			queue1.count();
		end = std::chrono::high_resolution_clock::now();
		res_time = std::chrono::duration_cast<ms>(end - start).count();
		cout << "My stack=" << res_time << endl;
	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
	};
	getchar();
	return 0;

}

