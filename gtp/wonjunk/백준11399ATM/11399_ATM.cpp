/// ATM 앞 줄을 선 사람 수 : N명
/// i번째 사람이 돈을 인출하는데 걸리는 시간 : p_i
/// => 모든 사람이 돈을 인출하는데 걸리는 최소 시간을 구하라. (줄을 선 순서에 따라 총 시간이 달라짐)
/// 
/// idea : 돈을 뽑는데 가장 적은 시간이 필요한 사람이 앞에 줄을 서면 총 시간이 줄어든다!
/// 

#include <iostream>

using namespace std;

int* input(int* n);
void solve(int* pTime, int n);
void sort(int* pTime, int n);
void getMinTime(int* pTime, int n);

int main(void) {
	int n;
	int* pTime = input(&n);
	solve(pTime, n);

	delete[] pTime;
	return 0;
}

int* input(int* n) {
	cin >> *n;

	int* pTime = new int[*n] {0};
	for (int i = 0; i < *n; i++) {
		cin >> pTime[i];
	}

	return pTime;
}

void solve(int* pTime, int n) {
	sort(pTime, n);
	getMinTime(pTime, n);
}


//Bubble Sort
//void sort(int* pTime, int n) {
//	int temp;
//
//	for (int i = 0; i < n-1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (pTime[i] > pTime[j]) {
//				temp = pTime[i];
//				pTime[i] = pTime[j];
//				pTime[j] = temp;
//			}
//		}
//	}
//}

//Selection Sort
//void sort(int* pTime, int n) {
//	int temp;
//	int mindex;
//	
//	for (int i = 0; i < n-1; i++) {
//		mindex = i;
//		for (int j = i + 1; j < n; j++) {
//			if (pTime[mindex] > pTime[j]) {
//				mindex = j;
//			}
//		}
//
//		temp = pTime[i];
//		pTime[i] = pTime[mindex];
//		pTime[mindex] = temp;
//	}
//}

//Insertion Sort
//void sort(int* pTime, int n) {
//	int temp;
//
//	for (int i = 1; i < n; i++) {
//		for (int j = i; j > 0; j--) {
//			if (pTime[j] < pTime[j-1]) {
//				temp = pTime[j];
//				pTime[j] = pTime[j-1];
//				pTime[j-1] = temp;
//			}
//			else {
//				break;
//			}
//		}
//	}
//}

void getMinTime(int* pTime, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += pTime[i] * (n - i);
	}
	cout << result << "\n";
}

