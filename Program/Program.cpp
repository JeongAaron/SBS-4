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
	void pop_pront()
	{
		if (head != nullptr)
		{
			Node* currentNode = head;
			head = currentNode->next;
			delete currentNode;
			size--;
		}
		else
		{
			cout << "empty" << endl;
		}
	}
	void Show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
	}
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;
		}
		else if (head->next != nullptr)
		{
			Node* previousNode = head;
			Node* deleteNode = head->next;
			while (deleteNode->next != nullptr)
			{
				previousNode = deleteNode;
				deleteNode = deleteNode->next;
			}
			previousNode->next = deleteNode->next;
			delete deleteNode;
			size--;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			size--;
		}
	}
	~SingleLinkedList()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			Node* nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
			//	cout << "delete" << endl;
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
	single.pop_back();
	single.pop_back();
	single.Show();
}
