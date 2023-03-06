#include<iostream>
#include<list>
#include<algorithm>
#define MAX 8
using namespace std;

list<int*> virus;

int map[MAX][MAX];
int copy_map[MAX][MAX];
bool visited[MAX][MAX];

int lo_x[] = { -1, 0, 1, 0 };
int lo_y[] = { 0, 1, 0, -1 };

int max_safety_zone;
int N, M;

void spread_virus();
void deploy_virus(int);
void get_safety_zone();

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back(new int[2] { i, j });
			}
		}
	}
	deploy_virus(3);
	cout << max_safety_zone << endl;
	return 0;
}


void get_safety_zone() {

	int safety_zone = 0;

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			if (copy_map[i][j] == 0)
				safety_zone += 1;
		}
	}

	if (max_safety_zone < safety_zone)
		max_safety_zone = safety_zone;
}

void spread_virus() {

	for (int i = 0; i < N; i += 1) {
		copy(map[i], map[i] + M, copy_map[i]);
	}
	memset(visited, false, sizeof(visited));
	list<int*> activated_virus(virus);

	int nx, ny;
	int size = activated_virus.size();

	while (size > 0) {

		int * location = activated_virus.front();
		int x = location[0];
		int y = location[1];
		activated_virus.pop_front();
		delete location;

		for (int i = 0; i < 4; i += 1) {

			nx = x + lo_x[i];
			ny = y + lo_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (copy_map[nx][ny] != 0 || visited[nx][ny])
				continue;

			copy_map[nx][ny] = 2;
			visited[nx][ny] = true;
			activated_virus.push_back(new int[2] {nx, ny});
		}
	}
	get_safety_zone();
}

void deploy_virus(int remain_wall) {

	if (remain_wall == 0) {

		spread_virus();
		return;
	}

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {

			if (map[i][j] == 0) {
				map[i][j] = 1;
				deploy_virus(remain_wall - 1);
				map[i][j] = 0;
			}
		}
	}
}
