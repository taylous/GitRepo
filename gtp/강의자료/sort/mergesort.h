#include<iostream>
using namespace std;

class MergeSort {

private:
	void sort(int[], int[], int, int);
	void merge(int[], int[], int, int, int);

public:
	MergeSort() {}
	~MergeSort() {}
	void sort(int[], int);
};

void MergeSort::merge(int dest[], int aux[], int low, int mid, int high) {

	for (int k = low; k <= high; k++) {
		aux[k] = dest[k];
	}

	int i = low, j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (i > mid)					dest[k] = aux[j++];
		else if (j > high)              dest[k] = aux[i++];
		else if (aux[j] <= aux[i])		dest[k] = aux[j++];
		else							dest[k] = aux[i++];
	}
}

void MergeSort::sort(int dest[], int aux[], int low, int high) {

	if (high <= low) return;

	int mid = low + (high - low) / 2;

	this->sort(dest, aux, low, mid);
	this->sort(dest, aux, mid + 1, high);
	this->merge(dest, aux, low, mid, high);

	for (int i = low; i <= high; i += 1)
		cout << dest[i] << " ";
	cout << endl;
}

void MergeSort::sort(int src[], int len) {

	int* aux = new int[len];
	for (int i = 0; i < len; i += 1)
		aux[i] = src[i];
	this->sort(src, aux, 0, len - 1);
	cout << endl;
}