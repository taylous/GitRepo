#include<iostream>
using namespace std;
#include<queue>
#define MAX 100

int N, M;
int haze[MAX + 2][MAX + 2] = { 0, };
bool visited[MAX + 2][MAX + 2] = { 0, }; //��� false�� �ʱ�ȭ
queue <pair<int, int>> q;

int ind_x[] = { 0, 1, 0, -1 }; // �ϵ�����
int ind_y[] = { -1, 0, 1, 0 };

int main() {
	//�Է�
	cin >> N >> M;

	string input;
	for (int i = 1; i <= N; i += 1) {
		cin >> input;
		for (int j = 1; j <= M; j += 1) {
			haze[i][j] = input[j - 1] - '0';
		}
	}

	for (int i = 0; i <= N+1 ; i += 1) {
		for (int j = 0; j <= M+1 ; j += 1) {
			cout << haze[i][j] << " " ;
		}
		cout << endl;
	}

	//ó�� ��ġ
	int x, y;
	int count = -1;
	q.push({ 1 , 1 });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		count += 1;

		//������üũ
		if (x == N && y == M) {
			break;
		}

		// Ž��
		int new_x, new_y;
		for (int i = 0; i < 4; i += 1) {
			new_x = x + ind_x[i];
			new_y = y + ind_y[i];

			if (haze[new_x][new_y] == 1 && visited[new_x][new_y] == false)  {
				//�湮�� �� �Է�
				q.push({ new_x , new_y });
				visited[new_x][new_y] = true;
			}

		}

	}
	
	cout << count << endl;

	for (int i = 0; i <= N + 1; i += 1) {
		for (int j = 0; j <= M + 1; j += 1) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}



