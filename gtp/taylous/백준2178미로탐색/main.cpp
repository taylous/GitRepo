#include<iostream>
#include<queue>
#define MAX 100
using namespace std;

int maze[MAX + 2][MAX + 2];

int lo_x[] = { -1, 0, 1, 0 };
int lo_y[] = { 0, 1, 0, -1 };

int N, M;

int escape_maze();

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i += 1) {

		string input;
		cin >> input;

		for (int j = 1; j <= M; j += 1) {
			maze[i][j] = input[j - 1] - '0';
		}
	}
	cout << escape_maze() << endl;
	return 0;
}

int escape_maze() {

	bool visited[MAX + 2][MAX + 2] = { false, };
	queue<pair<int, int>> q;
	int nx, ny, size, move = 0;
	bool flag = false;

	q.push({ 1, 1 });
	visited[1][1] = true;

	while (!q.empty() && !flag) {

		size = q.size();
		while (size-- > 0) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == N && y == M) {

				flag = true;
				break;
			}

			for (int i = 0; i < 4; i += 1) {

				nx = x + lo_x[i];
				ny = y + lo_y[i];

				if (maze[nx][ny] == 0 || visited[nx][ny])
					continue;

				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
		move += 1;
	}
	return move;
}
