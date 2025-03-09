#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>

class AdjacencyMatrix
{
private:
	int count;
	T vertex[SIZE];
	int matrix[SIZE][SIZE];
public:
	AdjacencyMatrix()
	{
		count = 0;
		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = 0;
			}
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
			cout << "Vertex is overflow" << endl;
		}
	}
	void edge(int i, int j)
	{
		if (count <= 0)
		{
			cout << "Vertex is Empty" << endl;
		}
		else
		{
			if (i >= count || i >= count)
			{
				cout << "Edge is out of range" << endl;
			}
			else
			{
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}
	void show()
	{
		cout << "  ";
		for (int i = 0; i < count;i++)
		{
			cout << vertex[i] << " ";
		}
		cout << endl;
		for (int j = 0; j < count;j++)
		{
			cout << vertex[j] << " ";
			for (int k = 0;k < count;k++)
			{
				cout << matrix[j][k] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	AdjacencyMatrix<char> matrix;
	matrix.push('A');
	matrix.push('B');
	matrix.push('C');
	matrix.edge(0, 1);
	matrix.edge(1, 2);
	matrix.show();

}
