#include <iostream>

using namespace std;

template <typename T>

class SingleLinkedList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		if (head == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
		}
		else
		{
			newNode->data = data;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		Node* currentNode = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
		}
		else
		{
			newNode->data = data;
			newNode->next = nullptr;
		}
		size++;
	}
};

int main()
{
	SingleLinkedList<int> single;
	single.push_front(10);
	single.push_front(20);
}
