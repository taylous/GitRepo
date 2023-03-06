#include<iostream>
#include<list>
#include<algorithm>
#define MAX 8
using namespace std;

list<int*> virus;

int lo_x[] = { -1, 0, 1, 0 };
int lo_y[] = { 0, 1, 0, -1 };

int max_safety_zone;
int N, M;

void clear(int**);
void spread_virus(int**);
void deploy_virus(int**, int);
void get_safety_zone(int**);

void print(int** map) {

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(void) {

	cin >> N >> M;
	int** map = new int* [N];
	for (int i = 0; i < N; i += 1) {
		map[i] = new int[M] {0, };
	}

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back(new int[2] { i, j });
			}
		}
	}
	deploy_virus(map, 3);
	cout << max_safety_zone << endl;
	clear(map);
	return 0;
}


void get_safety_zone(int** map) {

	int safety_zone = 0;

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			if (map[i][j] == 0)
				safety_zone += 1;
		}
	}

	if (max_safety_zone < safety_zone)
		max_safety_zone = safety_zone;
}

void spread_virus(int** map) {

	int** copy_map = new int* [N];
	bool** visited = new bool* [N];
	for (int i = 0; i < N; i += 1) {
		copy_map[i] = new int[M] {0, };
		visited[i] = new bool[M] {false, };
	}

	for (int i = 0; i < N; i += 1) {
		copy(map[i], map[i] + M, copy_map[i]);
	}
	list<int*> activated_virus(virus);
	int* location;
	int nx, ny;


	while (!activated_virus.empty()) {

		location = activated_virus.front();
		activated_virus.pop_front();

		for (int i = 0; i < 4; i += 1) {

			nx = location[0] + lo_x[i];
			ny = location[1] + lo_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] != 0 || visited[nx][ny])
				continue;

			copy_map[nx][ny] = 2;
			visited[nx][ny] = true;
			activated_virus.push_back(new int[2] {nx, ny});
		}
	}
	get_safety_zone(copy_map);
}

void deploy_virus(int** map, int remain_wall) {

	if (remain_wall == 0) {

		spread_virus(map);
		return;
	}

	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {

			if (map[i][j] == 0) {
				map[i][j] = 1;
				deploy_virus(map, remain_wall - 1);
				map[i][j] = 0;
			}
		}
	}

}

void clear(int** map) {
	for (int row = 0; row < N; row += 1)
		delete[] map[row];
	delete[] map;
}