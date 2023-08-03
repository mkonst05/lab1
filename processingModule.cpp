#include<iostream>
#include"processeingModule.h"
using namespace std;
double calculate_average(int** arr, int rows, int cols, int* rows_numbers)
{
    int index = 1;
    double sum = 0;
    for (int i = 0; i < rows; i++)
    {
        if (i != rows_numbers[index])
        {
            continue;
        }
        index++;
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "Сума: " << sum << endl;
    return (sum / rows_numbers[0]);
}
int* processing(int** arr, int rows, int cols)
{
    int* rows_numbers = new int[rows + 1] {0};
    int index = 1;

    for (int i = 0; i < rows; i++)
    {
        int positive_count = 0;
        int negative_count = 0;
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > 0)
            {
                positive_count++;
            }
            if (arr[i][j] < 0)
            {
                negative_count++;
            }
        }
        if (positive_count > negative_count)
        {
            rows_numbers[index] = i;
            index++;
            rows_numbers[0] += 1;
            cout << "Додатних чисел більше, ніж від'ємних у рядку " << i + 1 << endl;
        }
    }
    return rows_numbers;
}