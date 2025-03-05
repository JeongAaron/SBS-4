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
	const int& HashFuction(T key)
	{
		unsigned int hashIndex = (int)key % SIZE;
		return hashIndex;
	}
	template<>
	const int& HashFuction(const char* key)
	{
		int k = 0;
		for (int i = 0; i < strlen(key); i++)
		{
			k += key[i];
		}
		return k % SIZE;
	}
	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->Next = nullptr;
		return newNode;
	}
	void Insert(KEY key, VALUE value)
	{
		int hashindex = HashFuction(key);
		Node* newNode = CreateNode(key, value);
		if (bucket[hashindex].head == nullptr)
		{
			bucket[hashindex].head = newNode;
		}
		else
		{
			newNode->Next = bucket[hashindex].head;
			bucket[hashindex].head = newNode;
		}
		bucket[hashindex].count++;
	}
	void Remove(KEY key)
	{
		int hashindex = HashFuction(key);
		int count = bucket[hashindex].count;
		Node* currentNode = bucket[hashindex].head;
		Node* previousNode = nullptr;
		if (currentNode == nullptr)
		{
			cout << "Key not found" << endl;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashindex].head)
					{
						bucket[hashindex].head = currentNode->Next;
					}
					else
					{
						previousNode->Next = currentNode->Next;
					}
					bucket[hashindex].count--;
					delete currentNode;
					return;
				}
				else
				{
					previousNode = currentNode;
					currentNode = currentNode->Next;
				}
			}
			cout << "Key not found" << endl;
		}
	}
	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;
			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->Next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}
	}
};

int main()
{
	HashTable<const char*, int> hashTable;
	//hashTable.Insert("Sword", 10000);
	hashTable.Insert("Armor", 5000);
	hashTable.Remove("Sword");
	hashTable.Remove("Sword");
}
