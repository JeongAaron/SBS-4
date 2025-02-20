#include <iostream>

using namespace std;

template <typename T>

class CircleLinkedList
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
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (size == 0)
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (size == 0)
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}
	void show()
	{
		if(head != nullptr)
		{
			Node* currentNode = head->next;
			for (int i = 0; i < size; i++)
			{
				cout << currentNode->data << " ";
				currentNode = currentNode->next;
			}
		}
		cout << endl;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* deleteNode = head->next;
			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;
			size--;
		}
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* currentNode = head;
			if (head = head->next)
			{
				head = nullptr;
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					currentNode = currentNode->next;
				}
				head = currentNode;
				currentNode->next = deleteNode->next;
			}
			delete deleteNode;
			size--;
		}
	}
	void Size()
	{
		cout << "size : " << size << endl;
	}
	~CircleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

};
int main()
{
	CircleLinkedList<int> circleLinkedList;
	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	//circleLinkedList.push_back(30);
	circleLinkedList.pop_back();
	circleLinkedList.show();
	circleLinkedList.Size();
}
