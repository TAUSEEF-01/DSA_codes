#include <bits/stdc++.h>
using namespace std;

int n;

void generate_permutation(int arr[], int pos)
{
    if (pos == n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << arr[n - 1] << endl;
        return;
    }

    for (int i = 0; i <= 4; i++)
    {
        if (pos % 2 == i % 2)
        {
            arr[pos] = i;
            generate_permutation(arr, pos + 1);
        }
    }
}

int main()
{
    cin >> n;

    int arr[n];
    generate_permutation(arr, 0);

    return 0;
}
