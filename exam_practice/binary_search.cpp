#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int val)
{
    int low = 0;
    int high = n;

    while (low <= high) // very careful ---> <=
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }

        if (arr[mid] < val) // only < sign is used
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // high equals mid - 1
        }
    }

    return -1;
}

int lower_bound(int arr[], int n, int val)
{
    int low = 0;
    int high = n;

    while (low < high) // only < sign is used (different from binary search)
    {
        int mid = low + (high - low) / 2;

        if (val <= arr[mid]) // very careful ---> <= (different from binary search) // val before arr[mid]
        {
            high = mid; // here high; high equals only mid; not mid - 1
        }
        else
        {
            low = mid + 1;
        }
    }

    if (low < n && arr[low] < val)
    {
        low++;
    }

    return low;
}

int upper_bound(int arr[], int n, int val)
{
    int low = 0;
    int high = n;

    while (low < high) // only < sign is used (different from binary search)
    {
        int mid = low + (high - low) / 2;

        if (val >= arr[mid]) // very careful ---> >= (different from binary search) // val before arr[mid]
        {
            low = mid + 1; // here low
        }
        else
        {
            high = mid; // high equals only mid; not mid - 1
        }
    }

    if (low < n && arr[low] < val)
    {
        low++;
    }

    return low;
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

    sort(arr, arr + n); // sort the array for searching elements

    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;

        int pos;

        cout << "Binary search: ";
        pos = binary_search(arr, n, num);
        if (pos != -1)
        {
            cout << "Element found at index " << pos << endl;
        }
        else
        {
            cout << "Element not present!" << endl;
        }

        cout << "Lower bound: ";
        pos = lower_bound(arr, n, num);
        if (pos == n)
        {
            cout << "Lower bound doesn't exist!" << endl;
        }
        else
        {
            cout << "Lower bound of " << num << " is: " << arr[pos] << " at index: " << pos << endl;
        }

        cout << "Upper bound: ";
        pos = upper_bound(arr, n, num);
        if (pos == n)
        {
            cout << "Upper bound doesn't exist!" << endl;
        }
        else
        {
            cout << "Upper bound of " << num << " is: " << arr[pos] << " index: " << pos << endl;
        }

        cout << endl
             << endl;
    }
}