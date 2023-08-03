// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cstdlib>
#include"matrix_filling.h"
#include"processeingModule.h"
#include"create-delete_matrix.h"
using namespace std;
void show_matrix(int** arr, int rows, int cols);

struct matrix
{
    int **arr;
    int rows;
    int cols;
};
int main()
{
    matrix m;
    setlocale(LC_ALL, "");
   
    cout << "Введіть кількість РЯДКІВ матриці: ";
    cin >> m.rows;
    cout << "Введіть кількість СТОВПЦІВ матриці: ";
    cin >> m.cols;
    m.arr = create(m.rows, m.cols);
    int user_input;
    cout << "Оберіть спосіб заповнення матриці: " << endl;;
    cout << "Введіть 1, щоб заповнити матрицю власноруч." << endl;
    cout << "Введіть 2, щоб заповнити матрицю випадковими числами." << endl;
    cin >> user_input;
    switch (user_input)
    {
    case 1:manualFilling(m.arr, m.rows, m.cols);
        break;
    case 2:randomFilling(m.arr, m.rows, m.cols);
        break;
    default:cout << "ПОМИЛКА" << endl;
        break;
    }
    show_matrix(m.arr, m.rows, m.cols);

    int* rows_numbers = processing(m.arr,m. rows, m.cols);
    if (rows_numbers[0] == 0)
    {
        cout << "Потрібних рядків не було знайдено." << endl;
        return -1;
    }
    double result = calculate_average(m.arr, m.rows, m.cols, rows_numbers);
    cout << "Результат: " << result << endl;
    delete[] rows_numbers;
    delete_matrix(m.arr, m.rows, m.cols);
}

void show_matrix(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
