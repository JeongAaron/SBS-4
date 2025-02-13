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
		if (head == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
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
		}
		size++;
	}
	void print()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
	}
	~SingleLinkedList()
	{
		Node* currentNode;
		while (head->next != nullptr)
		{
			currentNode = head;
			head = head->next;
			delete currentNode;

		}
	}
};

int main()
{
	SingleLinkedList<int> single;
	single.push_front(10);
	single.push_front(20);
	single.push_front(30);
	single.push_back(40);
	single.push_back(50);
	single.print();
}
