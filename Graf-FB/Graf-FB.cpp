#include <iostream>
#include "floid.h"

using namespace std;

int i, j,n=6;
bool* visited = new bool[n];

int matrix[6][6] = { {0,3,0,0,6,20},
					  {3,0,8,3,0,0},
					  {0,8,0,4,0,5},
					  {0,3,4,0,0,0},
					  {6,0,0,0,0,7},
					  {20,0,5,0,7,0},
};


//����� � �������
void DFS(int st)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((matrix[st][r] != 0) && (!visited[r]))
			DFS(r);
}

int main()
{
    setlocale(LC_ALL, "ru");



      
    int matrix[6][6] = { {0,3,0,0,6,20},
                          {3,0,8,3,0,0},
                          {0,8,0,4,0,5},
                          {0,3,4,0,0,0},
                          {6,0,0,0,0,7},
                          {20,0,5,0,7,0},
    };
    
    cout << " ������� ��������� ����� :" << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    int a[6][6] = { {0,3,1000,1000,6,20},
                    {3,0,8,3,1000,1000},
                    {1000,8,0,4,1000,5},
                    {1000,3,4,0,1000,1000},
                    {6,1000,1000,1000,0,7},
                    {20,1000,5,1000,7,0}, };

       floid(a);// ������� ����������  ����������� ���������� ����� ��������


		   int start;
		   cout << "Матрица смежности графа: " << endl;
		   for (i = 0; i < n; i++)
		   {
			   visited[i] = false;
			   for (j = 0; j < n; j++)
				   cout << " " << matrix[i][j];
			   cout << endl;
		   }
		   cout << "Стартовая вершина >> "; cin >> start;
		   //массив посещенных вершин
		   bool* vis = new bool[n];
		   cout << "Порядок обхода: ";
		   DFS(start - 1);
		   delete[]visited;
		


    
    
    return 0;
}
