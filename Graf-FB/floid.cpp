#include <iostream>

#include "floid.h"

void floid(int(&a)[6][6]) {
    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];

    std::cout<< std::endl << " matrix  dlin putei :" << std::endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            std::cout << a[i][j] << "\t";
        std::cout << std::endl;
    }
    
}