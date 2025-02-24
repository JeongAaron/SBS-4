#include <iostream>

#define SIZE 4
using namespace std;

template <typename T>

class CircleQueue
{
private:
	int rear;
	int front;
	T container[SIZE];
public:
	CircleQueue()
	{
		rear = SIZE - 1;
		front = SIZE - 1;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void push(T data)
	{
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
	}
};

int main()
{

}
