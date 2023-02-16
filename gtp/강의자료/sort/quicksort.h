#pragma once
class QuickSort {

private:
	int* arr;
	int len;

public:
	QuickSort(int arr[], int len) {
		this->arr = new int[len];
		this->len = len;

		for (int i = 0; i < len; i += 1)
			this->arr[i] = arr[i];
	}
	~QuickSort() {
		delete arr;
	}
	int partition(int, int);
	void sort(int, int);
	int* getArr();
	int getLen();
};

int* QuickSort::getArr() {
	return this->arr;
}

int QuickSort::getLen() {
	return this->len;
}

int QuickSort::partition(int left, int right) {

	int pivot_index = left;
	int low = left + 1;
	int high = right;
	int t;

	while (low <= high) {

		while (low <= right && this->arr[low] <= this->arr[pivot_index])
			low++;
		while (high > left && this->arr[high] > this->arr[pivot_index])
			high--;

		if (low >= high)
			break;

		t = this->arr[low];
		this->arr[low] = this->arr[high];
		this->arr[high] = t;
	}
	t = this->arr[high];
	this->arr[high] = this->arr[pivot_index];
	this->arr[pivot_index] = t;
	return high;
}

void QuickSort::sort(int left, int right) {

	if (left < right) {
		int pivot_index = this->partition(left, right);

		this->sort(left, pivot_index - 1);
		this->sort(pivot_index + 1, right);
	}
}