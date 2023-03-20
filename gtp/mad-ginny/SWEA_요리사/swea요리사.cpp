#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)
#include<iostream>
using namespace std;
#include<stdio.h>

int T, N;
int** synergy;
bool* ingredient;
void combination(int, int);

int main() {

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	while (T--) {

		// 음식 개수와 시너지 입력
		cin >> N;
		synergy = new int* [N];
		ingredient = new bool[N] {0, }; // default: false(A)

		for (int n = 0; n < N; n += 1) {
			synergy[n] = new int[N];

			for (int m = 0; m < N; m += 1) {
				cin >> synergy[n][m];
			}
		}

		// N개 중 절반을 선택하는 조합
		combination(0, N/2);
	
	}

	return 0;
}

void combination(int idx, int cnt) {
	if (cnt <= 0) {
		return;
	}

	for (int i = idx; i < N; i += 1) {
		if (ingredient[i]==0) { // ingredient가 false이면(선택되지 않았다면)
			ingredient[i] = 1;
			combination(i, cnt--);
			ingredient[i] = 0;
		}
	}
}

