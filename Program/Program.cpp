#include <iostream>

using namespace std;

template <typename T>

class Vector
{
private:
	int size;
	int capacity;
	T* container;
public:
	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;
	}
	void resize(int newSize)
	{
		return newSize * 2;
	}
	void push_back(T data)
	{
		if (container == nullptr)
		{
			capacity = 1;
			T* newContainer[capacity] = new T;
			newContainer[capacity] = data;
		}
		else
		{

		}
	}
};

int main()
{

}
