class InsertionSort {

private:
	int* arr;
	int len;

public:
	InsertionSort(int arr[], int len) {
		this->arr = new int[len];
		this->len = len;

		for (int i = 0; i < len; i += 1)
			this->arr[i] = arr[i];
	}
	~InsertionSort() {
		delete arr;
	}
	void sort();
	int* getArr();
	int getLen();
};

int* InsertionSort::getArr() {
	return this->arr;
}

int InsertionSort::getLen() {
	return this->len;
}

void InsertionSort::sort() {

	int j;
	for (int i = 1; i < this->len; i += 1) {
		int target = this->arr[i];

		for (j = i - 1; j >= 0 && this->arr[j] > target; j -= 1) {
			this->arr[j + 1] = this->arr[j];
		}
		this->arr[j + 1] = target;
	}
}