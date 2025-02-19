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
	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}

	}
	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;

		}
		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			if (size == 1)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;
				head = head->next;
			}
			delete deleteNode;
			size--;
		}
	}
	void pop_back()
	{
		if (size == 0)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;
			if (size == 1)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->previous->next = nullptr;
				tail = tail->previous;
			}
			delete deleteNode;
			size--;
		}
	}
	void Size()
	{
		cout << size << endl;
	}
	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedList;
	doubleLinkedList.push_front(4);
	doubleLinkedList.push_front(3);
	doubleLinkedList.push_front(2);
	doubleLinkedList.push_front(1);
	doubleLinkedList.push_back(5);
	doubleLinkedList.push_back(6);
	doubleLinkedList.Size();
	doubleLinkedList.pop_front();
	doubleLinkedList.pop_back();
	doubleLinkedList.show();
}
