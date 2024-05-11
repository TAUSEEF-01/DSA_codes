#include <iostream>

using namespace std;

void heapify(int arr[], int upperBound, int lowerBound){
	int largestIdx = lowerBound;
	int leftIdx = 2*lowerBound;
	int rightIdx = 2*lowerBound + 1;

	if(leftIdx < upperBound && arr[leftIdx] > arr[largestIdx]){
		largestIdx = leftIdx;
	}
	if(rightIdx < upperBound && arr[rightIdx] > arr[largestIdx]){
		largestIdx = rightIdx;
	}

	if(largestIdx != lowerBound){
		swap(arr[lowerBound], arr[largestIdx]);
		heapify(arr, upperBound, largestIdx);
	}

}

void heapSort(int arr[], int sizeOfArray){

	for(int idx = sizeOfArray/2 - 1; idx >= 0; idx--){
		heapify(arr, sizeOfArray, idx);
	}

	for(int idx = sizeOfArray - 1; idx > 0; idx --){
		swap(arr[0], arr[idx]); 
		heapify(arr, idx, 0); 
	}
}

void cookieStuff(int arr[], int sizeOfArray, int minSweetness){
	heapSort(arr, sizeOfArray);
	int newCookie = -1, noOfIterations = 0, removedElements = 0, max_value = 1000000001;
	while(arr[0] < minSweetness || (sizeOfArray - removedElements) <= 1){
		newCookie = arr[0] + 2 * arr[1];
		arr[0] = max_value;
		arr[1] = max_value;
		arr[sizeOfArray++] = newCookie;
		heapSort(arr, sizeOfArray);
		noOfIterations++;
		removedElements+=2;
	}
	cout << noOfIterations << endl;
}

int main() {
	int arr_size = 100000;
	int n, k;
	cin >> n >> k;
	int arr[arr_size];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cookieStuff(arr, n, k);
}