#include<iostream>
#include "selection.h"
#include "insertion.h"
#include "quicksort.h"
using namespace std;


void print(int* arr, int len) {
	for (int i = 0; i < len; i += 1) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void) {

	int arr[] = { 7, 5, 1, 2, 9 };
	int arr2[] = { 9, 3, 1, 7, 2 };
	int arr3[] = { 7, 9, 2, 1, 5, 6, 3, 4, 8, 10 };

	SelectionSort select_sort = {arr, 5};
	select_sort.sort();

	InsertionSort insertion_sort = { arr2, 5 };
	insertion_sort.sort();

	QuickSort quick_sort = { arr3, 10 };
	quick_sort.sort(0, 9);

	print(select_sort.getArr(), select_sort.getLen());
	print(insertion_sort.getArr(), insertion_sort.getLen());
	print(quick_sort.getArr(), quick_sort.getLen());

	return 0;
}