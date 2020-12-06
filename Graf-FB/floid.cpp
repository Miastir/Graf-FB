#include <iostream>

#include "floid.h"

void floid(int(&matrix)[6][6]) {
    // заполнения бесконечностями всмето 0 для расчета расстояния
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++) {
            if (matrix[i][j] == 0 && (i!=j)) { matrix[i][j] = 1000; }
        }
    }

    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    std::cout<< std::endl << " Матрица минимальных длин между вершинами :" << std::endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
    
}