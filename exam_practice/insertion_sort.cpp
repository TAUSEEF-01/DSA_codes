#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int store = a[i];
        int j = i - 1;

        while (store < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = store;
    }
}

void bubble_sort(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]) // both in terms of j ---> j, j + 1
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
            {
                pos = j;
            }
        }
        int temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
    }
}

// void countSort(int array[], int size)
// {
//     int output[10];
//     int count[10];
//     int max = array[0];

//     for (int i = 1; i < size; i++)
//     {
//         if (array[i] > max)
//             max = array[i];
//     }

//     for (int i = 0; i <= max; ++i)
//     {
//         count[i] = 0;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         count[array[i]]++;
//     }

//     for (int i = 1; i <= max; i++)
//     {
//         count[i] += count[i - 1];
//     }

//     for (int i = size - 1; i >= 0; i--)
//     {
//         output[count[array[i]] - 1] = array[i];
//         count[array[i]]--;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         array[i] = output[i];
//     }
// }

void countSort(int array[], int size)
{
    int count[100];
    int output[100];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // insertion_sort(arr, n);
    countSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}

// void insertion_sort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int store = arr[i];
//         int j = i - 1;

//         while (store < arr[j] && j >= 0)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = store;
//     }
// }
