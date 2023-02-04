#include<iostream>
using namespace std;

int** init(int, int);
bool seek_dirty_area(int**, int, int, int);
int reverse_direction(int);
void free(int***, int);

int loX[] = {-1, 0, 1, 0};
int loY[] = { 0, 1, 0, -1};

int main(void) {

	int rx, ry, d;
	int n, m;
	int clean = 0;
	int seek, check_d;

	cin >> n >> m;
	cin >> rx >> ry >> d;

	int** room = init(n, m);

	while (true) {

		if (room[rx][ry] == 0) {
			room[rx][ry] = -1;
			clean += 1;
		}
		seek = 0;
		check_d = d;

		while(seek != 15) {
			check_d = (check_d == 0 ? 3 : check_d - 1);
			
			if (seek_dirty_area(room, rx, ry, check_d)) {
				d = check_d;
				break;
			}
			d = check_d;
			seek |= (1 << check_d);
		}

		if (seek == 15) {
			int reverse_d = reverse_direction(d);
			if (room[rx + loX[reverse_d]][ry + loY[reverse_d]] == 1) {
				break;
			}
			rx += loX[reverse_d];
			ry += loY[reverse_d];
		}
		else {
			rx += loX[d];
			ry += loY[d];
		}
	}
	cout << clean << endl;
	free(&room, n);
	return 0;
}

int** init(int n, int m) {

	int** matrix = nullptr;
	matrix = new int* [n];
	for (int i = 0; i < n; i += 1) {
		matrix[i] = new int[m];
	}

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < m; j += 1)
			cin >> matrix[i][j];
	}
	return matrix;
}

bool seek_dirty_area(int** room, int rx, int ry, int check_d) {
	int x = rx + loX[check_d];
	int y = ry + loY[check_d];
	return room[x][y] == 0;
}

int reverse_direction(int current_d) {
	return current_d ^ (1 << 1);
}

void free(int*** matrix, int n) {

	for (int i = 0; i < n; i += 1)
		delete[] (*matrix)[i];
	delete *matrix;
}
