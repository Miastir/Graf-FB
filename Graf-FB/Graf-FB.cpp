#include <iostream>
#include "floid.h"

using namespace std;


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
    
    cout << " matrix smejnosti :" << endl;

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

       floid(a);// алгорим нахождения  кротчайшего расстояния между городами

        







































    
    
    return 0;
}
