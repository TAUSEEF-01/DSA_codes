#include <bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(int arr[], int sz, int pos)
{
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;

    int max_pos = pos;

    if (l < sz && arr[l] > arr[max_pos])
        max_pos = l;

    if (r < sz && arr[r] > arr[max_pos])
        max_pos = r;

    if (max_pos != pos)
    {
        swap(arr[max_pos], arr[pos]);
        heapify(arr, sz, max_pos);
    }
}

void heapsort(int arr[], int n)
{
    // 1st heapify it ---> build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i); // pos -----> i and size -----> n
    }

    // then heapify the array again from the end so that the  ---> heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // pos -----> 0 and size ----> i; not n
    }
}

void delete_node(int arr[], int &n)
{
    // 1st heapify the array then call this function ---> all you need to do is heapify the array once
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    swap(arr[0], arr[n - 1]);
    heapify(arr, n - 1, 0);

    n--;
}

void max_heap(int arr[], int n)
{
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
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

    heapsort(arr, n);

    // int nn = n;
    // delete_node(arr, n);
    // delete_node(arr, n);

    // heapsort(arr, n);

    printArray(arr, n);

    return 0;
}
