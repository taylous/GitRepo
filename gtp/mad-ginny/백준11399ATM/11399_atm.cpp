#include<iostream>;
using namespace std;

int* init(int);
int sum(int, int*);

int main(void) {

	// 입력: 줄을 선 사람 수와 인출 시간
	int N;
	cin >> N;
	int* p = init(N);

	// 정렬
	int min_index;
	for (int i = 0; i < (N - 1); i += 1) {
		min_index = i;
		for (int j = (i + 1);j < (N - 1 - i);j += 1) {
			if (p[min_index] > p[j]) min_index = j;
		}
		int tmp = p[min_index];
		p[min_index] = p[i];
		p[i] = tmp;
	}

	// 각 사람의 인출 시간의 합
	int time = sum(N, p);
	cout << time;

	//출력
	return 0;

}

int* init(int N) {
	int* p = new int[N];
	for (int i = 0; i < N; i += 1) {
		cin >> p[i];
	}
	return p;
}

int sum(int N, int* p) {
	int s = 0;
	for (int i = 0;i < N;i += 1) {
		for (int j = 0;j <= i;j += 1) {
			s += p[j];
		}
	}
	return s;
}
