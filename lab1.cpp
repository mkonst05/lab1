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


int main(void)
{
    srand(time(NULL));
    int arr[ROWS][COLS];

    randomFilling(arr);
    //manualFilling(arr);
    print_matrix(arr);

    int* arr3 = processing(arr);
    for (int i = 0; i < ROWS+1; i++)
    {
        cout << arr3[i] << " ";
    }
    delete[] arr3;
}

void randomFilling(int arr[ROWS][COLS])
{
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
    int* m = new int[ROWS+1] {0};
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

        cout << "Positives in row " << i + 1 << ": " << positive_count << endl;
        cout << "Negatives in row " << i + 1 << ": " << negative_count << endl;
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
            cin>>arr[i][j];
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
