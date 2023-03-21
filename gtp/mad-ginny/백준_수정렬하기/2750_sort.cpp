#include<iostream>
using namespace std;

int* sort(int*, int);

int main() {
	int n;
	int* arr;

	//입력
	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i += 1) {
		cin >> arr[i];
	}

	//sort
	int* res;
	res = sort(arr, n);

	//출력
	for (int i = 0; i < n; i += 1) {
		cout << res[i] << endl;
	}

	// delete arr, res 어디 넣어야하는지 모르겠다 ㅜ

	return 0;
}

int* sort(int* arr, int n) {
	int target,j;
	for (int i = 1; i < n; i += 1) {
		target = arr[i];
		for (j = i - 1; j >= 0 && arr[j] >= target; j -= 1) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = target;
	}

	return arr;
}