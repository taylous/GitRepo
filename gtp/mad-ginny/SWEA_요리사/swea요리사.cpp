#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int T, N;
int** synergy;
bool* ingredient;
int combination(int, int);
int diff_synergy();

int main() {

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for(int i=1; i <= T; i+=1){

		// 음식 개수와 시너지 입력
		cin >> N;
		synergy = new int* [N];
		ingredient = new bool[N]; // default: false(A)

		for (int n = 0; n < N; n += 1) {
			synergy[n] = new int[N];

			for (int m = 0; m < N; m += 1) {
				cin >> synergy[n][m];
			}
		}

		// N개 중 절반을 선택하는 조합
		int min_diff = combination(0, N/2);

		cout << "#" << i << " " << min_diff << endl;
	
	}

	delete synergy;
	delete ingredient;

	return 0;
}

int combination(int idx, int cnt) {
	int min_diff = INT_MAX;

	if (cnt == 0) {
		int diff = diff_synergy();
		if (min_diff > diff) {
			min_diff = diff;
		}
		return min_diff;
	}

	for (int i = idx; i < N; i += 1) {
		if (ingredient[i]==0) { // ingredient가 false이면(선택되지 않았다면)
			ingredient[i] = 1;
			combination(i+1, cnt--);
			ingredient[i] = 0;
		}
	}
}

int diff_synergy() {

	/*
	// Error: vector subscript out of range
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i += 1) {
		ingredient[i] ? A.push_back(i) : B.push_back(i);
	}
	
	int A_sum = 0;
	int B_sum = 0;
	for (int i = 0; i < (N / 2 - 1); i += 1) {
		for (int j = i + 1; j < N / 2; j += 1) {
			A_sum = A_sum + synergy[A[i]][A[j]] + synergy[A[j]][A[i]];
			B_sum = B_sum + synergy[B[i]][B[j]] + synergy[B[j]][B[i]];
		}
	}
	*/

	int A_sum = 0;
	int B_sum = 0;
	int synergy_sum = 0;
	for (int i = 0; i < (N - 1); i += 1) {
		for (int j = 0; j < N; j += 1) {
			if (ingredient[i]==0 && ingredient[j]==0) {
				synergy_sum = synergy[i][j] + synergy[j][i];
				A_sum += synergy_sum;
			}
			else if (ingredient[i] == 1 && ingredient[j] == 1) {
				synergy_sum = synergy[i][j] + synergy[j][i];
				B_sum += synergy_sum;
			}
			else {
				continue;
			}
		}
	}

	int diff = ((A_sum > B_sum) ? (A_sum - B_sum) : (B_sum - A_sum));

	return diff;
	
}
