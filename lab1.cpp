// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cstdlib>

using namespace std;

#define ROWS 3
#define COLS 3

void print_matrix(int arr[ROWS][COLS]);
int* processing(int arr2[ROWS][COLS]);
void randomFilling(int arr[ROWS][COLS]);
void manualFilling(int arr[ROWS][COLS]);
double calculate_average(int arr[ROWS][COLS], int m[ROWS+1]);

int main(void)
{
    setlocale(LC_ALL, "");
    int arr[ROWS][COLS];
    int user_input;
    cout << "Оберіть спосіб заповнення матриці: " << endl;;
    cout << "Введіть 1, щоб заповнити матрицю власноруч." << endl;
    cout << "Введіть 2, щоб заповнити матрицю випадковими числами." << endl;
    cin >> user_input;
    switch (user_input)
    {
    case 1:manualFilling(arr);
        break;
    case 2:randomFilling(arr);
        break;
    default:cout << "ERROR" << endl;
        break;
    }
    print_matrix(arr);

    int* arr3 = processing(arr);
    for (int i = 0; i < ROWS + 1; i++)
    {
        cout << arr3[i] << " ";
    }cout << endl;
    if (arr3[0] == 0)
    {
        cout << "Потрібних рядків не було знайдено." << endl;
        return -1;
    }
    double result = calculate_average(arr, arr3);
    cout << "Result: " << result << endl;
    delete[] arr3;
}
double calculate_average(int arr[ROWS][COLS], int m[ROWS + 1])
{
    int index=0;
    double sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (i != m[index + 1])
        {
            continue;
        }index++;
        for (int j = 0; j < COLS; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "Sum: " << sum << endl;
    return (sum / m[0]);
}

void randomFilling(int arr[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 20 - 10;
        }
    }
}

void print_matrix(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int* processing(int arr2[ROWS][COLS])
{
    int* m = new int[ROWS + 1] {0};
    int index = 1;

    for (int i = 0; i < ROWS; i++)
    {
        int positive_count = 0;
        int negative_count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (arr2[i][j] > 0)
            {
                positive_count++;
            }
            if (arr2[i][j] < 0)
            {
                negative_count++;
            }
        }
        if (positive_count > negative_count)
        {
            m[index] = i;
            index++;
            m[0] += 1;
            cout << "P is more than N in row " << i + 1 << endl;
        }
        //
    }
    return m;
}
void manualFilling(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
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
