#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Heap
{
    int arr[1000000];
    int sz = 0;

    void insert(int val)
    {
        arr[sz++] = val;
    }

    void heapify(int n, int indx)
    {
        int left_indx = indx * 2 + 1;
        int right_indx = indx * 2 + 2;

        int max_indx = indx;
        if (left_indx < n && arr[left_indx] > arr[max_indx])
        {
            max_indx = left_indx;
        }
        if (right_indx < n && arr[right_indx] > arr[max_indx])
        {
            max_indx = right_indx;
        }

        if (indx != max_indx)
        {
            int temp = arr[indx];
            arr[indx] = arr[max_indx];
            arr[max_indx] = temp;

            heapify(n, max_indx);
        }
    }

    void max_heap()
    {
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    void heap_sort()
    {
        max_heap();

        for (int i = sz - 1; i >= 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(i, 0);
        }
    }

    void deleteNode(int num)
    {
        int pos = 0;
        for (int i = 0; i < sz; i++)
        {
            if (num == arr[i])
            {
                pos = i;
                break;
            }
        }

        int temp = arr[pos];
        arr[pos] = arr[sz - 1];
        arr[sz - 1] = temp;

        sz--;
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    int index_val(int i)
    {
        if (i > sz || i <= 0)
        {
            return -INT_MAX;
        }
        return arr[i];
    }

    void print_array()
    {
        cout << '[';
        for (int i = 0; i < sz - 1; i++)
        {
            cout << arr[i] << ',';
        }
        cout << arr[sz - 1] << ']';
        cout << endl;
    }
};

int main()
{
    Heap *heap = new Heap();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        heap->insert(x);
    }

    // heap->max_heap();
    // heap->print_array();

    heap->heap_sort();
    heap->print_array();

    return 0;
}

