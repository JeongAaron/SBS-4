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
		if (newSize == 0)
		{
			newSize = 1;
		}
		else
		{
			newSize = newSize * 2;
		}
		T* newContainer = new T[newSize];
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = container[i];
		}
		delete[] container;
		container = newContainer;
		capacity = newSize;
	}
	void push_back(T data)
	{
		if (size == capacity)
		{
			resize(capacity);
		}
		container[size++] = data;
	}

	void Size()
	{
		cout << "Size : "<< size << endl;
	}
	void Capacity()
	{
		cout << "Capacity : "<< capacity << endl;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << container[i] << " ";
		}
	}
};

int main()
{
	Vector<int> vector;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);
	vector.push_back(60);
	vector.push_back(70);
	vector.push_back(80);
	vector.Capacity();
	vector.Size();
	vector.print();
}
