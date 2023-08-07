// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cstdlib>
#include"matrix_filling.h"
#include"processeingModule.h"
#include"create-delete_matrix.h"
#include"structMtrx.cpp";
using namespace std;
void show_matrix(struct matrix *m);


int main(int argc,char* argv[])
{
    struct matrix* m = new struct matrix;
    setlocale(LC_ALL, "");
   
    cout << "Введіть кількість РЯДКІВ матриці: ";
    cin >> m->rows;
    cout << "Введіть кількість СТОВПЦІВ матриці: ";
    cin >> m->cols;
    m->arr = create(m->rows, m->cols);
    int user_input;
    cout << "Оберіть спосіб заповнення матриці: " << endl;;
    cout << "Введіть 1, щоб заповнити матрицю власноруч." << endl;
    cout << "Введіть 2, щоб заповнити матрицю випадковими числами." << endl;
    cin >> user_input;
    switch (user_input)
    {
    case 1:manualFilling(m);
        break;
    case 2:randomFilling(m);
        break;
    default:cout << "ПОМИЛКА" << endl;
        break;
    }
    show_matrix(m);

    int* rows_numbers = processing(m);
    if (rows_numbers[0] == 0)
    {
        cout << "Потрібних рядків не було знайдено." << endl;
        return -1;
    }
    double result = calculate_average(m, rows_numbers);
    cout << "Результат: " << result << endl;
    delete[] rows_numbers;
    delete_matrix(m);
}

void show_matrix(struct matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            cout << m->arr[i][j] << " ";
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
