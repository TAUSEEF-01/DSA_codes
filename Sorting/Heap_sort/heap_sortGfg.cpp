// // C++ program for implementation of Heap Sort

// #include <iostream>
// using namespace std;

// // To heapify a subtree rooted with node i
// // which is an index in arr[].
// // n is size of heap
// void heapify(int arr[], int N, int i)
// {

//     // Initialize largest as root
//     int largest = i;

//     // left = 2*i + 1
//     int l = 2 * i + 1;

//     // right = 2*i + 2
//     int r = 2 * i + 2;

//     // If left child is larger than root
//     if (l < N && arr[l] > arr[largest])
//         largest = l;

//     // If right child is larger than largest
//     // so far
//     if (r < N && arr[r] > arr[largest])
//         largest = r;

//     // If largest is not root
//     if (largest != i) {
//         swap(arr[i], arr[largest]);

//         // Recursively heapify the affected
//         // sub-tree
//         heapify(arr, N, largest);
//     }
// }

// // Main function to do heap sort
// void heapSort(int arr[], int N)
// {

//     // Build heap (rearrange array)
//     for (int i = N / 2 - 1; i >= 0; i--)
//         heapify(arr, N, i);

//     // One by one extract an element
//     // from heap
//     for (int i = N - 1; i > 0; i--) {

//         // Move current root to end
//         swap(arr[0], arr[i]);

//         // call max heapify on the reduced heap
//         heapify(arr, i, 0);
//     }
// }

// // A utility function to print array of size n
// void printArray(int arr[], int N)
// {
//     for (int i = 0; i < N; ++i)
//         cout << arr[i] << " ";
//     cout << "\n";
// }

// // Driver's code
// int main()
// {

    // int n;
    // cin >> n;

    // int arr[n];

    // for(int i=0; i<n; i++)
    // {
    //     cin >> arr[i];
    // }

//     // Function call
//     heapSort(arr, n);

//     cout << "Sorted array is \n";
//     printArray(arr, n);
// }

// Heap Sort in C++

#include <iostream>
using namespace std;


// Print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    // printArray(arr, n);
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
        // printArray(arr, n);
    }

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}



// Driver code
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
        // printArray(arr, n);
    }

    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}