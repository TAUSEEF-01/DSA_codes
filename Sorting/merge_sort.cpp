#include <bits/stdc++.h>
using namespace std;

/*
1 2 3 4 5 6
0 1 2 3 4 5

0 2 4
2 - 0 + 1 --> 0, 1, 2 --> sz1 = mid - low + 1;
4 - 2 --> 3, 4 --> sz2 = high - mid;
*/

void merge(int a[], int low, int mid, int high)
{
    int sz1 = mid - low + 1, sz2 = high - mid;
    int L[sz1], R[sz2];

    int l = 0, r = 0, pos = low; // pos equals low

    for (int i = low, j = 0; i <= mid; i++, j++) // be careful --> i <= mid; i starts from low
    {
        L[j] = a[i];
    }
    for (int i = mid + 1, j = 0; i <= high; i++, j++) // be careful --> i <= high
    {
        R[j] = a[i];
    }

    while (l < sz1 && r < sz2)
    {
        if (L[l] < R[r])
        {
            a[pos] = L[l];
            l++;
        }
        else
        {
            a[pos] = R[r];
            r++;
        }
        pos++;
    }

    while (l < sz1)
    {
        a[pos] = L[l];
        l++;
        pos++;
    }

    while (r < sz2)
    {
        a[pos] = R[r];
        r++;
        pos++;
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);

    merge(a, low, mid, high);
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