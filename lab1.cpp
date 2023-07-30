// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cstdlib>

using namespace std;

void show_matrix(int** arr, int rows, int cols);
int* processing(int** arr, int rows, int cols);
void randomFilling(int** arr, int rows, int cols);
void manualFilling(int** arr, int rows, int cols);
double calculate_average(int** arr, int rows, int cols, int* rows_numbers);
int** create(int rows, int cols);
int main(void)
{
    setlocale(LC_ALL, "");
    int rows;
    int cols;
    cout << "Введіть кількість РЯДКІВ матриці: ";
    cin >> rows;
    cout << "Введіть кількість СТОВПЦІВ матриці: ";
    cin >> cols;
    int** arr = create(rows, cols);
    int user_input;
    cout << "Оберіть спосіб заповнення матриці: " << endl;;
    cout << "Введіть 1, щоб заповнити матрицю власноруч." << endl;
    cout << "Введіть 2, щоб заповнити матрицю випадковими числами." << endl;
    cin >> user_input;
    switch (user_input)
    {
    case 1:manualFilling(arr, rows, cols);
        break;
    case 2:randomFilling(arr, rows, cols);
        break;
    default:cout << "ПОМИЛКА" << endl;
        break;
    }
    show_matrix(arr, rows, cols);

    int* rows_numbers = processing(arr, rows, cols);
    if (rows_numbers[0] == 0)
    {
        cout << "Потрібних рядків не було знайдено." << endl;
        return -1;
    }
    double result = calculate_average(arr, rows, cols, rows_numbers);
    cout << "Результат: " << result << endl;
    delete[] rows_numbers;
    for (int b = 0; b < rows; b++)
    {
        delete[] arr[b];
    }
    delete[]arr;
}
int** create(int rows, int cols)
{
    int** arr = new int* [rows];
    for (int a = 0; a < rows; a++)
    {
        arr[a] = new int[cols];
    }
    return arr;
}

double calculate_average(int** arr, int rows, int cols, int *rows_numbers)
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

void randomFilling(int** arr, int rows, int cols)
{
    srand(time(NULL));
    for (int i = 0; i <rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20 - 10;
        }
    }
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
