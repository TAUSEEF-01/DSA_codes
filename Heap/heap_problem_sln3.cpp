#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000

struct MinHeap
{
    int sweetnessArr[MAX_SIZE];
    int indexArr[MAX_SIZE];
    int size = 0;

    void insert(int sweetness, int index)
    {
        if (size == MAX_SIZE)
        {
            cout << "Heap is full. Cannot insert." << endl;
            return;
        }
        size++;
        int idx = size - 1;
        sweetnessArr[idx] = sweetness;
        indexArr[idx] = index;

        while (idx > 0 && sweetnessArr[idx] < sweetnessArr[(idx - 1) / 2])
        {
            swap(sweetnessArr[idx], sweetnessArr[(idx - 1) / 2]);
            swap(indexArr[idx], indexArr[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    int deleteMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty. Cannot delete minimum." << endl;
            return -1; // or any appropriate handling for an empty heap
        }
        int minIndex = indexArr[0];
        sweetnessArr[0] = sweetnessArr[size - 1];
        indexArr[0] = indexArr[size - 1];
        size--;
        min_heapify(0);
        return minIndex;
    }

    void deleteElement(int index)
    {
        int idx;
        for (idx = 0; idx < size; idx++)
        {
            if (indexArr[idx] == index)
                break;
        }

        if (idx == size)
        {
            cout << "Element not found in the heap." << endl;
            return;
        }

        sweetnessArr[idx] = sweetnessArr[size - 1];
        indexArr[idx] = indexArr[size - 1];
        size--;
        min_heapify(idx);
    }

    int getMin()
    {
        if (size == 0)
        {
            cout << "Heap is empty." << endl;
            return INT_MAX; 
        }
        return sweetnessArr[0];
    }

private:
    void min_heapify(int idx)
    {
        int smallest = idx;
        while (true)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < size && sweetnessArr[left] < sweetnessArr[smallest])
                smallest = left;

            if (right < size && sweetnessArr[right] < sweetnessArr[smallest])
                smallest = right;

            if (smallest != idx)
            {
                swap(sweetnessArr[idx], sweetnessArr[smallest]);
                swap(indexArr[idx], indexArr[smallest]);
                idx = smallest;
            }
            else
            {
                break;
            }
        }
    }
};

int cookies(int k, int A[], int n) {
    MinHeap minHeap;
    for (int i = 0; i < n; ++i) {
        minHeap.insert(A[i], i);
    }
    int operations = 0;
    while (minHeap.size > 1 && minHeap.sweetnessArr[0] < k) {
        int least1 = minHeap.deleteMin();
        int least2 = minHeap.deleteMin();
        int new_cookie = A[least1] + 2 * A[least2];
        A[least1] = new_cookie; // Update A[least1] to store the new sweetness
        minHeap.insert(new_cookie, least1);
        ++operations;
    }
    if (minHeap.size > 0 && minHeap.sweetnessArr[0] >= k) {
        return operations;
    } else {
        return -1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int A[MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << cookies(k, A, n) << endl;
    return 0;
}