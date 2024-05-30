#include <bits/stdc++.h>
using namespace std;

// min heap --------------------------------->
void heapify(int arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int minPos = i;

    if (l < n && arr[l] < arr[minPos])
    {
        minPos = l;
    }
    if (r < n && arr[r] < arr[minPos])
    {
        minPos = r;
    }

    if (minPos != i)
    {
        swap(arr[i], arr[minPos]);
        heapify(arr, n, minPos);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    // build max heap first

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int deleteNode(int arr[], int &n)
{
    // build max heap first

    swap(arr[0], arr[n - 1]);
    heapify(arr, n - 1, 0);

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

    buildMinHeap(arr, n);
    printArray(arr, n);

    heapSort(arr, n);
    printArray(arr, n);

    buildMinHeap(arr, n);
    while (n)
    {
        cout << deleteNode(arr, n) << ' ';
    }

    return 0;
}