class SelectionSort {

private:
	int* arr;
	int len;

public:
	SelectionSort(int arr[], int len) {
		this->arr = new int[len];
		this->len = len;

		for (int i = 0; i < len; i += 1)
			this->arr[i] = arr[i];
	}
	~SelectionSort() {
		delete arr;
	}
	void sort();
	int* getArr();
	int getLen();
};

int* SelectionSort::getArr() {
	return this->arr;
}

int SelectionSort::getLen() {
	return this->len;
}

void SelectionSort::sort() {

	for (int i = 0; i < this->len - 1; i += 1) {
		int minIndex = i;

		for (int j = i + 1; j < this->len; j += 1) {
			if (this->arr[minIndex] > this->arr[j]) {
				minIndex = j;
			}
		}
		int t = this->arr[i];
		this->arr[i] = this->arr[minIndex];
		this->arr[minIndex] = t;
	}
}