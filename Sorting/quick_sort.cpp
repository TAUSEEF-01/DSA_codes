#include <bits/stdc++.h>
using namespace std;

/*
time complexity:
worst case: O(n ^2) --> when the array is sorted
average case: O(n * log(n))

space complexity:
auxilary space: O(1)

give preferences over merge sort in some cases because the worst case for time complexity rarely occurs
and in average cases the time complexity is same as the merge sort, but in case of space complexity the
quick sort takes less space than the merge sort
*/

int partition(int arr[], int low, int high)
{
    int pos = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < arr[high])
        {
            pos++;
            swap(arr[i], arr[pos]);
        }
    }

    pos++;
    swap(arr[pos], arr[high]);

    return pos;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndx = partition(arr, low, high);

        quickSort(arr, low, pivotIndx - 1);
        quickSort(arr, pivotIndx + 1, high);
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

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}