#include<iostream>
#include"create-delete_matrix.h"
using namespace std;
int** create(int rows, int cols)
{
    int** arr = new int* [rows];
    for (int a = 0; a < rows; a++)
    {
        arr[a] = new int[cols];
    }
    return arr;
}
int** delete_matrix(int** arr, int rows, int cols)
{
    for (int b = 0; b < rows; b++)
    {
        delete[] arr[b];
    }
    delete[]arr;
    return 0;
}