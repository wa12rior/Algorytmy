#include<iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int pivot(int arr[], int left, int right) {
	
	int leftPos = left;
	int rightPos = right;
	int temp;
	int currentPivot = arr[left];
	while (1) {
		while (arr[leftPos] < currentPivot) {
			leftPos++;
		} 
		
		while (arr[rightPos] > currentPivot) {
			rightPos--;
		}
		if (leftPos < rightPos) {
			temp = arr[leftPos];
			arr[leftPos] = arr[rightPos];
			arr[rightPos] = temp;
			leftPos++;
			rightPos--;
		} else {
			return rightPos;
		}
	}
}

void quicksort(int arr[], int left, int right) {
	
	int pivotIndex;
	if (left < right) {
		pivotIndex = pivot(arr, left, right);
		quicksort(arr, left, pivotIndex);
		quicksort(arr, pivotIndex + 1, right);
	}
}

int main() {
	const int SIZE = 20;
	int arr[SIZE];
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < SIZE; i++) arr[i] = rand() % 100;
	cout << "Before quicksort" << endl << endl;
	for (i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
	
	quicksort(arr, 0, SIZE);
	cout << endl<< "After quicksort" << endl << endl;
	for (i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
 
	delete [] arr;
	
	return 0;
}
