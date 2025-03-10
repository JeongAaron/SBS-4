#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>

class AdjacencyList
{
private:
	int count;
	T vertex[SIZE];
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};
	Node* list[SIZE];
public:
	AdjacencyList()
	{
		count = 0;
		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			list[i] = NULL;
		}
	}
	void push(T data)
	{
		if (count < SIZE)
		{
			vertex[count++] = data;
			
		}
		else
		{
			cout << "Adjacency List is overflow" << endl;
		}
	}
	void edge(int i, int j)
	{
		if (count <= 0)
		{
			cout << "Adjacency List is Empty" << endl;
		}
		else
		{
			if (i >= count || j >= count)
			{
				cout << "Index is out of range" << endl;
			}
			else
			{
				list[i] = new Node(vertex[j], list[i]);
				list[j] = new Node(vertex[i], list[j]);
			}
		}
		
	}
	~AdjacencyList()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (list[i] != nullptr)
			{
				delete[] list[i];
			}
		}
	}
};
int main()
{

}
