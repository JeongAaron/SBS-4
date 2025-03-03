#include <iostream>
#define SIZE 6

using namespace std;

template <typename KEY, typename VALUE>

class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* Next;
	};
	struct Bucket
	{
		int count;
		Node* head;
	};
	Bucket bucket[SIZE];
public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}
	template<typename T>
	const int & HashFuction(T key)
	{
		unsigned int hashIndex = (int)key % SIZE;
		return hashIndex;
	}
	template<>
	const int & HashFuction(const char* key)
	{
		int k = 0;
		for (int i = 0; i < strlen(key); i++)
		{
			k += key[i];
		}
		return k % SIZE;
	}
};

int main()
{
	HashTable<int,string> hashTable;
	cout << hashTable.HashFuction("key") << endl;
	cout << hashTable.HashFuction(12) << endl;

}
