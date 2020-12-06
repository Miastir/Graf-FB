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


//поиск в глубину
void DFS(int st)
{
	int r;
	std::cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((matrix[st][r] != 0) && (!visited[r]))
			DFS(r);
}

int main()
{
    setlocale(LC_ALL, "ru");
	
	std::cout << "Исходная матрица расчитана для графа с 6 вершинами \n";
	// заполнения бесконечностями всмето 0 для расчета расстояния
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			for (i = 0; i < n; i++)
			{
				std::cout << "введите вес пути между вершинами \n"<<i+1<<"-"<<j+1;
				std::cout << endl;
				std::cin >> matrix[i][j];
			}
		}
	}
	
	// заготовка для теста
	/*
	int matrix[6][6] = {{0,3,0,0,6,20},//Матрица весов графа
                        {3,0,8,3,0,0},
                        {0,8,0,4,0,5},
                        {0,3,4,0,0,0},
                        {6,0,0,0,0,7},
                        {20,0,5,0,7,0},
						};
	*/

    std::cout << " Вывод исходной матрицы :" << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
			std::cout << matrix[i][j] << "\t";
		std::cout << endl;
    }

       floid(matrix);// Метод флойда


		   int start;


		       // заполнения бесконечностями всмето 0 для расчета расстояния
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++) {
            if (matrix[i][j] == 0 && (i!=j)) { matrix[i][j] = 1000; }
        }
    }
	
	
		   for (i = 0; i < n; i++)
		   {  visited[i] = false;
		   }
		   
		   std::cout << endl;
		   std::cout << "Введите вершину с которой будет искаться максимальный путь в графе \n"; 
		   std::cin >> start;
		   //массив посещенных вершин
		   bool* vis = new bool[n];
		   std::cout << endl;
		   std::cout << "Порядок обхода при длинном пути: ";
		   DFS(start - 1);
		   delete[]visited;
		   std::cout << endl;
		


    
    
    return 0;
}
