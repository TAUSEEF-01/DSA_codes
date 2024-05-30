#include <bits/stdc++.h>
using namespace std;

#define sz 1000000

struct min_heap
{
    int arr[sz];
    int ind[sz];
    int size = 0;

    void insert(int value, int index)
    {
        if (size == sz)
        {
            return;
        }

        size++;
        int idx = size - 1;
        arr[idx] = value;
        ind[idx] = index;

        while (idx > 0 && arr[idx] < arr[(idx - 1) / 2])
        {
            swap(arr[idx], arr[(idx - 1) / 2]);
            swap(ind[idx], ind[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    int deleteMin()
    {
        if (size == 0)
        {
            return -1; 
        }
        int minIndex = ind[0];
        arr[0] = arr[size - 1];
        ind[0] = ind[size - 1];
        size--;
        min_heapify(0);
        return minIndex;
    }

    void deleteElement(int index)
    {
        int idx;
        for (idx = 0; idx < size; idx++)
        {
            if (ind[idx] == index)
                break;
        }

        if (idx == size)
        {
            return;
        }

        arr[idx] = arr[size - 1];
        ind[idx] = ind[size - 1];
        size--;
        min_heapify(idx);
    }

    int getMin()
    {
        if (size == 0)
        {
            return INT_MAX; 
        }
        return arr[0];
    }

    void min_heapify(int idx)
    {
        int smallest = idx;
        while (true)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != idx)
            {
                swap(arr[idx], arr[smallest]);
                swap(ind[idx], ind[smallest]);
                idx = smallest;
            }
            else
            {
                break;
            }
        }
    }
};

void solve() {

    min_heap min_heap;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        min_heap.insert(x, i);
    }


    for(int i = 0; i < n; ++i)
    {
        cout << min_heap.getMin() << endl;
        min_heap.deleteMin();
    }

}

int main()
{
    solve();

    return 0;
}