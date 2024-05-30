#include <bits/stdc++.h>
using namespace std;

// build max heap starts here ------------------------------------------->
void heapify(int arr[], int sz, int pos)
{
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;

    int maxPos = pos;
    if (l < sz && arr[l] > arr[maxPos])
    {
        maxPos = l;
    }
    if (r < sz && arr[r] > arr[maxPos])
    {
        maxPos = r;
    }

    if (maxPos != pos)
    {
        swap(arr[pos], arr[maxPos]);
        heapify(arr, sz, maxPos);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
// build max heap ends here ------------------------------------------->

// build min heap starts here ------------------------------------------->
void heapify_min(int arr[], int sz, int pos)
{
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;

    int minPos = pos;
    if (l < sz && arr[l] < arr[minPos])
    {
        minPos = l;
    }
    if (r < sz && arr[r] < arr[minPos])
    {
        minPos = r;
    }

    if (minPos != pos)
    {
        swap(arr[pos], arr[minPos]);
        heapify_min(arr, sz, minPos);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_min(arr, n, i);
    }
}
// build min heap ends here ------------------------------------------->

void heapSort(int arr[], int n)
{
    // for (int i = n / 2 - 1; i >= 0; i--)
    // {
    //     heapify(arr, n, i);
    // }
    // buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        // heapify_min(arr, i, 0);
    }
}

int deleteNode(int arr[], int &n)
{
    // for (int i = n / 2 - 1; i >= 0; i--)
    // {
    //     heapify(arr, n, i);
    // }
    // buildMaxHeap(arr, n);

    swap(arr[0], arr[n - 1]);
    heapify(arr, n - 1, 0);
    // heapify_min(arr, n - 1, 0);
    n--;
    return arr[n];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
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

    // buildMaxHeap(arr, n);
    // printArray(arr, n);

    buildMinHeap(arr, n);
    printArray(arr, n);

    // heapSort(arr, n);
    // printArray(arr, n);

    // buildMaxHeap(arr, n);
    // while (n)
    // {
    //     cout << deleteNode(arr, n) << ' ';
    // }

    return 0;
}

// void heapify_min(int arr[], int end, int i)
// {
// int left = 2 * i + 1;
// int right = 2 * i + 2;
// int small = i;

// if (left < end)
// {
//     if (arr[small] > arr[left])
//     {
//         small = left;
//     }
// }
// if (right < end)
// {
//     if (arr[small] > arr[right])
//     {
//         small = right;
//     }
// }
// if (small != i)
// {
//     swap(arr[i], arr[small]);
//     heapify_min(arr, end, small);
// }
// }
