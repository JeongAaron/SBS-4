#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>

class LinearQueue
{
private:
	int front;
	int rear;
	T container[SIZE];
public:
	LinearQueue()
	{
		front = 0;
		rear = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void push(T data)
	{
		{
			if (rear >= SIZE)
			{
				cout << "LinearQueue Overflow" << endl;
			}
			else
			{
				container[rear++] = data;
			}
		}
	}
	void pop()
	{
		if (empty())
		{
			cout << "Empty" << endl;
		}
		else
		{
			container[front++] = NULL;
		}
	}
	bool empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	const T& Front()
	{
		if (empty())
		{
			cout << "Linear Queue is Empty" << endl;
			exit(1);
		}
		else
		{
			return container[front];
		}
	}
	const int& Size()
	{
		return rear - front;
	}
	const T& back()
	{
		if (empty())
		{
			cout << "Linear Queue is Empty" << endl;
			exit(1);
		}
		else
		{
			return container[rear - 1];
		}
	}
};

int main()
{
	LinearQueue<int> linearQueue;
	linearQueue.push(10);
	linearQueue.push(20);
	linearQueue.push(30);
	linearQueue.push(40);
	linearQueue.push(50);
	//linearQueue.pop();
	//linearQueue.pop();
	//linearQueue.pop();
	//linearQueue.pop();
	//linearQueue.pop();
	cout << "Size : " << linearQueue.Size() << endl;
	cout << "Front : " << linearQueue.Front() << endl;
	cout << "Back : " << linearQueue.back() << endl;
	while (linearQueue.empty() == false)
	{
		cout << linearQueue.Front() << " ";
		linearQueue.pop();
	}
	cout << endl;

}
