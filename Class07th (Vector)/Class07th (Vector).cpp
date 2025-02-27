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
		for (int i = 0; i < newSize; i++)
		{
			newContainer[i] = NULL;
		}
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = container[i];
		}
		if (container != nullptr)
		{
			delete[] container;
		}
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
	void pop_back()
	{
		if (size == 0)
		{
			cout << "Vector is Empty" << endl;
		}
		else
		{
			container[--size] = NULL;
		}
	}
	const T& front()
	{
		if (size != 0)
		{
			return container[0];
		}
	}
	const T& back()
	{
		if (size != 0)
		{
			return container[size - 1];
		}
	}
	const int& Size()
	{
		return size;
	}
	const int& Capacity()
	{
		return capacity;
	}
	const T& operator[](const int& index)
	{
		return  container[index];
	}
	void begin()
	{
		cout << &front() << endl;
	}
	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
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
	vector.pop_back();
	cout << "Size : " << vector.Size() << endl;
	cout << "Capacity : " << vector.Capacity() << endl;
	cout << "Front : " << vector.front() << endl;
	cout << "Back : " << vector.back() << endl;
	for (int i = 0; i < vector.Size(); i++)
	{
		cout << vector[i] << " ";
	}
}
