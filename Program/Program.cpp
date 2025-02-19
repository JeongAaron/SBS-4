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
		if (size == 0)
		{
			newNode->data = data;
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->data = data;
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}
	void show()
	{
		if (size == 0)
		{
			cout << "empty" << endl;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != head)
			{
				currentNode = currentNode->next;
				cout << currentNode->data << " ";
			}
			cout << head->data << " ";
		}
	}
};
int main()
{
	CircleLinkedList<int> circleLinkedList;
	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);
	circleLinkedList.push_back(40);
	circleLinkedList.show();


}
