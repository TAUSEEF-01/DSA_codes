#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int sz1 = mid - low + 1;
    int sz2 = high - mid;

    int L[sz1], R[sz2];

    for (int i = low, j = 0; i <= mid; i++, j++)
    {
        L[j] = arr[i];
    }
    for (int i = mid + 1, j = 0; i <= high; i++, j++)
    {
        R[j] = arr[i];
    }

    int l = 0, r = 0, pos = low;

    while (l < sz1 and r < sz2)
    {
        if (L[l] < R[r])
        {
            arr[pos] = L[l];
            l++;
        }
        else
        {
            arr[pos] = R[r];
            r++;
        }
        pos++;
    }

    while (l < sz1)
    {
        arr[pos] = L[l];
        pos++;
        l++;
    }

    while (r < sz2)
    {
        arr[pos] = R[r];
        pos++;
        r++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}