#include <iostream>

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
	//	void append(const char* word)
	//	{
	//		size = strlen(pointer) + strlen(word) + 1;
	//		char * newPointer = new char[size];
	//		for (int i = 0; i < strlen(pointer); i++)
	//		{
	//			newPointer[i] = pointer[i];
	//		}
	//		for (int i = 0; i < strlen(word); i++)
	//		{
	//			newPointer[strlen(pointer) + i] = word[i];
	//		}
	//		if (pointer != nullptr)
	//		{
	//			delete[] pointer;
	//		}
	//		pointer = newPointer;
	//	}
	void append(const char* word)
	{
		int resize = size;
		size = size + strlen(word) + 1;
		char* newPointer = new char[size];
		for (int i = 0; i < resize; i++)
		{
			newPointer[i] = pointer[i];
		}
		for (int i = 0; i < strlen(word) + 1; i++)
		{
			newPointer[resize + i] = word[i];
		}
		delete[] pointer;
		pointer = newPointer;
	}
	int Size()
	{
		return size - 1;
	}
	long long Find(const char* word)
	{
		int s = 0;
		int F = strlen(word);
		for (int i = 0; i < size; i++)
		{
			if (pointer[i] == word[i])
			{
				continue;
			}
			else
			{
				break;
			}
		}

		return s;
		
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
	string = "apple";
	string.append(" Four");
	string.append(" X");
	cout << "Size : "<< string.Size() << endl;
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
}
