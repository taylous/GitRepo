#include <iostream>
#include <string>
#include <queue>
#include <climits>

using namespace std;

struct loc {
	int x;
	int y;
	int power;

	loc() : x(0), y(0), power(1) {}
	loc(int X, int Y, int Power) : x(X), y(Y), power(Power) {}
};

/// Function List
int** input(int n, int m);
int*** init_distArr(int n, int m);
/// <summary>
/// BFS활용하여 최단거리 구함
/// </summary>
/// <param name="Map"></param>
/// <param name="distanceArr"></param>
/// <param name="n"></param>
/// <param name="m"></param>
void solve(int** Map, int*** distanceArr, int n, int m);
/// <summary>
/// 동적할당 배열 메모리 해제
/// </summary>
/// <param name="Addr"> 배열 포인터</param>
/// <param name="n"> </param>
void MemoryFree(int*** Addr, int n);
void MemoryFree(int**** Addr, int n, int m);

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	int N, M;
	cin >> N >> M;

	int** Map = input(N, M);
	int*** dist = init_distArr(N, M);

	solve(Map, dist, N, M);

	MemoryFree(&Map, N);
	MemoryFree(&dist, N, M);

	return 0;
}


int** input(int n, int m)
{
	string Data;

	int** Map = new int* [n];
	for (int i = 0; i < n; i++)
	{
		Map[i] = new int[m];
	}


	for (int i = 0; i < n; i++)
	{
		cin >> Data;
		for (int j = 0; j < m; j++)
		{
			Map[i][j] = (int)(Data[j] - 48);
		}
	}

	return Map;
}

int*** init_distArr(int n, int m)
{
	int*** arr = new int** [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int* [m];
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = new int[2];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				arr[i][j][k] = INT_MAX;
			}
		}
	}
	arr[0][0][1] = 1;

	return arr;
}


void solve(int** Map, int*** distance, int n, int m)
{
	queue<loc>* Queue = new queue<loc>();
	loc cur(0, 0, 1);
	loc next;

	Map[0][0] = -1;
	Queue->push(cur);
	do
	{
		cur = Queue->front(); Queue->pop();
		for (int i = 0; i < 4; i++)
		{
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			next.power = cur.power;
			if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) { continue; }
			if ((Map[next.x][next.y] == -1 && distance[next.x][next.y][1] != INT_MAX) ||
				(Map[next.x][next.y] == 1 && next.power == 0)) {
				continue;
			}
			if (Map[next.x][next.y] == 1) {
				next.power--;
			}
			else { Map[next.x][next.y] = -1; }
			if (distance[next.x][next.y][next.power] > distance[cur.x][cur.y][cur.power] + 1 ||
				distance[next.x][next.y][next.power] == INT_MAX)
			{
				distance[next.x][next.y][next.power] = distance[cur.x][cur.y][cur.power] + 1;
				Queue->push(next);
			}
		}
	} while (!Queue->empty());

	if (distance[n - 1][m - 1][0] == INT_MAX && distance[n - 1][m - 1][1] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << min(distance[n - 1][m - 1][0], distance[n - 1][m - 1][1]);
	}
}


void MemoryFree(int*** Addr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[](*Addr)[i];
	}
	delete[] * Addr;
}

void MemoryFree(int**** Addr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			delete[](*Addr)[i][j];
		}
		delete[](*Addr)[i];
	}
	delete[] * Addr;
}