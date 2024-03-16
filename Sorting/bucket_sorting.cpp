#include<bits/stdc++.h>
using namespace std;
#define ll long long

void bucket_sort(int a[], int sz, int n)
{
    vector<int> bucket[10];
    for(int i=0; i<n; i++)
    {
        int num = a[i] / (int)pow(10, sz-1);
        int rem = num % 10;
        bucket[rem].push_back(a[i]);
    }
    int pos=0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<bucket[i].size(); j++)
        {
            a[pos++]=bucket[i][j];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    int maxi=0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        maxi=max(maxi, abs(a[i]));
    }

    int sz = ceil(log(maxi));
    for(int i=1; i<=sz; i++)
    {
        bucket_sort(a, i, n);
    }

    for(int i=0; i<n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}




// #include <iostream>
// #include<algorithm>

// using namespace std;

// void insertionSort(float arr[], int n) {
//     for (int i = 1; i < n; ++i) {
//         float key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }


// void bucketSort(float arr[], int n) {
//     // Find maximum and minimum values in the array
//     float minValue = arr[0];
//     float maxValue = arr[0];
//     for (int i = 1; i < n; i++) {
//         minValue = min(minValue, arr[i]);
//         maxValue = max(maxValue, arr[i]);
//     }

//     // Calculate the range of each bucket
//     float range = (maxValue - minValue) / n;
//     // cout << range << endl;

//     // Create an array of arrays (buckets)
//     int numOfBuckets = n;
//     int maxBucketSize = n; // Assuming each bucket can contain all elements
//     float buckets[numOfBuckets][maxBucketSize];
//     int bucketCounts[numOfBuckets] = {0};

//     // Put array elements into buckets
//     for (int i = 0; i < n; i++) {
        
//         int bucketIndex = (arr[i] - minValue) / range;
//         //boundary ele
//         float diff=(arr[i]-minValue)/range-bucketIndex;
//         if(diff==0 && arr[i]!=minValue){
//              buckets[bucketIndex-1][bucketCounts[bucketIndex]++] = arr[i];
//         }
//         else {
//         buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
//         }
//     }

//     // Sort individual buckets
//     for (int i = 0; i < numOfBuckets; i++) {
//         insertionSort(buckets[i], bucketCounts[i]);
//     }

//     // Concatenate sorted buckets into original array
//     int index = 0;
//     for (int i = 0; i < numOfBuckets; i++) {
//         for (int j = 0; j < bucketCounts[i]; j++) {
//             arr[index++] = buckets[i][j];
//         }
//     }
// }

// int main() {
//     float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
//     int n = sizeof(arr) / sizeof(arr[0]);

    
//     bucketSort(arr, n);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }














    // int val;
    // Vector *node;
    // int ind;
    // Vector()
    // {
    //     val = 0;
    //     ind = 0;
    //     node = (Vector*) calloc(sizeof(Vector), 10);
    // }

    // void resize()
    // {
    //     node = (Vector*) realloc(node, sizeof(node) * 2);
    // }

    // void add(int value)
    // {
    //     node->val = value;
    // }

    // void push_back(int value)
    // {
    //     if(ind >= size())
    //     {
    //         resize();
    //     }

    // }

    // int size()
    // {
    //     return ind;
    // }




// struct Vector
// {
//     int size;
//     int* value;
//     int ind;

//     Vector()
//     {
//         size = 5;
//         ind = 0;
//         value = (int*)calloc(size, sizeof(int));
//         if(value == NULL)
//         {
//             printf("Memory not allocated.\n");
//             exit(0);
//         }
//     }

//     void resize(int new_size)
//     {
//         value = (int*)realloc(value, new_size * sizeof(int));
//         if(value == NULL)
//         {
//             printf("Memory not allocated.\n");
//             exit(0);
//         }
//         size = new_size;
//     }

//     int getValue(int pos)
//     {
//         if(pos>=ind)
//         {
//             printf("No index exists.\n");
//             exit(0);
//         }
//         else
//         {
//             return value[pos];
//         }
//     }

//     void push_back(int num)
//     {
//         if(ind == size)
//         {
//             size *= 2;
//             resize(size);
//         }
//         value[ind++]=num;
//     }
    
//     int arraySize()
//     {
//         return ind;
//     }

//     void erase()
//     {
//         free(value);
//     }

// };