﻿#include <iostream>

#define SIZE 8

using namespace std;

template <typename T>

class PriorityQueue
{
private:
	int index;
	T container[SIZE];
public:
	PriorityQueue()
	{
		index = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void push(T data)
	{
		if (index + 1 >= SIZE)
		{
			cout << "Priority Queue Overflow" << endl;
		}
		else
		{
			container[++index] = data;
			int child = index;
			int parent = child / 2;
			while (child > 1)
			{
				if (container[parent] < container[child])
				{
				std:swap(container[parent], container[child]);
				}
				child = parent;
				parent = child / 2;
			}
		}
	}
	const T& top()
	{
		return container[1];
	}
	const bool empty()
	{
		if (index <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void pop()
	{
		if (index < 1)
		{
			cout << "Priority Queue Empty" << endl;
		}
		else
		{
			container[1] = container[index];
			container[index--] = NULL;
			int parent = 1;
			while (parent * 2 <= index)
			{
				int child = parent * 2;
				if (container[child] < container[child + 1])
				{
					child++;
				}
				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[parent], container[child]);
					parent = child;
				}
			}
		}
	}
};

int main()
{
	PriorityQueue<int> priorityQueue;
	priorityQueue.push(30);
	priorityQueue.push(20);
	priorityQueue.push(50);
	priorityQueue.push(60);
	priorityQueue.push(10);
	priorityQueue.push(70);
	priorityQueue.push(100);
	while (priorityQueue.empty() == false)
	{
		cout << priorityQueue.top() << endl;
		priorityQueue.pop();
	}
}
