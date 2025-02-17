#include <iostream>

using namespace std;

template <typename T>

class DoubleLinkedList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void push_pront(T data)
	{
		Node* newNode = new Node;
		if (head == nullptr && tail == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
			newNode->previous = nullptr;
			size++
		}
		else
		{
			head->previous = newNode;
			newNode->data = data;
			newNode->next = head;
			newNode->previous = nullptr;
			head = newNode;
			size++
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		if (head == nullptr && tail == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
			newNode->previous = nullptr;
			size++
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
			newNode->data = data;
			newNode->next = nullptr;
			newNode->previous = currentNode;
			size++
		}
	}
	void pop_pront()
	{
		if (size == 0)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* currentNode = head;
			if (size == 1)
			{
				delete currentNode;
				size--;
			}
			else
			{
				while (currentNode->previous != nullptr)
				{
					currentNode = currentNode->previous;
				}
				currentNode->next = head;
				head->previous = currentNode->previous;
				delete currentNode;
				size--;
			}
		}
	}

};

int main()
{
	DoubleLinkedList<int> dobleLinkedList;
	dobleLinkedList.push_pront(10);
	dobleLinkedList.push_pront(20);
}
