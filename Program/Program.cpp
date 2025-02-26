﻿#include <iostream>

using namespace std;

class String 
{
private:
	char* pointer;
	int size;
public:
	String()
	{
		pointer = nullptr;
		size = 0;
	}
	void operator = (const char* word)
	{
		size = strlen(word) + 1;
		if (pointer == nullptr)
		{
			pointer = new char[size];
			for (int i = 0; i < size; i++)
			{
				pointer[i] = word[i];
			}
		}
		else
		{
			char* newPointer = new char[size];
			for (int i = 0; i < size; i++)
			{
				newPointer[i] = word[i];
			}
			delete[] pointer;
			pointer = newPointer;
		}
	}
	const char& operator[](const int& index)
	{
		return  pointer[index];
	}
	int Size()
	{
		return size - 1;
	}
	~String()
	{
		if (pointer != nullptr)
		{
			delete[] pointer;
		}
	}
};
int main()
{
	String string;
	string = "key";
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
	string = "box";
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
}
