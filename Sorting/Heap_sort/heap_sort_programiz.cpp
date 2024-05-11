#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int i)
{
    int size = arr.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, largest);
    }
}
void insert(vector<int> &arr, int newNum)
{
    int size = arr.size();
    if (size == 0)
    {
        arr.push_back(newNum);
    }
    else
    {
        arr.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, i);
        }
    }
}

void deleteNode(vector<int> &arr, int num)
{
    int size = arr.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
            break;
    }

    int temp = arr[i];
    arr[i] = arr[size - 1];
    arr[size - 1] = temp;

    arr.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i);
    }
}

void heapifySort(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifySort(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifySort(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    vector<int> heapTree;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int v;
            cin >> v;
            insert(heapTree, v);
        }
        else if (x == 2)
        {
            int v;
            cin >> v;
            deleteNode(heapTree, v);
        }
        else
        {
            heapSort(heapTree);
            cout << heapTree[0] << endl;
        }
    }

}