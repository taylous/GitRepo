#include<iostream>
using namespace std;

class MergeXSort {

private:
	const int CUTOFF = 7;
	void sort(int[], int[], int, int);
	void merge(int[], int[], int, int, int);
	void insertion_sort(int[], int, int);

public:
	MergeXSort() {}
	~MergeXSort() {}
	void sort(int[], int);
};

void MergeXSort::insertion_sort(int arr[], int low, int high) {
	for (int i = low; i <= high; i++)
		for (int j = i; j > low && arr[j] < arr[j - 1]; j--) {
			int t = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = t;
		}
}

void MergeXSort::merge(int src[], int dest[], int low, int mid, int high) {

	int i = low, j = mid + 1;
	for (int k = low; k <= high; k++) {
		if (i > mid)					dest[k] = src[j++];
		else if (j > high)              dest[k] = src[i++];
		else if (src[j] < src[i])		dest[k] = src[j++];
		else							dest[k] = src[i++];
	}
}

void MergeXSort::sort(int src[], int dest[], int low, int high) {

	if (high <= low + this->CUTOFF) {
		this->insertion_sort(dest, low, high);
		return;
	}

	int mid = low + (high - low) / 2;

	this->sort(dest, src, low, mid);
	this->sort(dest, src, mid + 1, high);
	this->merge(src, dest, low, mid, high);

	for (int i = low; i <= high; i += 1)
		cout << dest[i] << " ";
	cout << endl;
}

void MergeXSort::sort(int src[], int len) {

	int* aux = new int[len];
	for (int i = 0; i < len; i += 1)
		aux[i] = src[i];
	this->sort(aux, src, 0, len - 1);
	cout << endl;
}