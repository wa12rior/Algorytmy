#include<iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void heapify(int arr[], int n, int i) { 
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 

void heapSort(int arr[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
        
    for (int i = n-1; i> = 0; i--) { 

        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}

int main() {
	const int SIZE = 20;
	int arr[SIZE];
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < SIZE; i++) arr[i] = rand() % 100;
	cout << "Before heap sort" << endl << endl;
	for (i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
	
	heapSort(arr, SIZE);
		
	cout << endl<< "After heap sort" << endl << endl;
	for (i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
 
	delete [] arr;
	
	return 0;
}
