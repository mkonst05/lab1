#include"matrix_filling.h"
#include<iostream>
#include<cstdlib>
using namespace std;
void randomFilling(int** arr, int rows, int cols)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20 - 10;
        }
    }
}
void manualFilling(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}