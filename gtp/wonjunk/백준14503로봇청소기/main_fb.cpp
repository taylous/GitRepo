#include <iostream>

using namespace std;

/*
* 📢 c, c++ 에선 함수의 경우 소문자로 시작합니다.
* 
*  그리고 camel case가 아닌 snake case를 사용하는데요.
*  coding convention 이라는 것이 협업하는 사람들끼리의 "약속"이라
*  "c, c++ 은 무조건이거야!" 같은 강제성은 없지만,
*  trend로 봤을 땐 snake case가 압도적이므로 되도록이면 해당 convention을 적용하는 것이 좋습니다! 😊
*/
void Cleaner_Working(int** Map, int* r, int* c, int* d, bool* flag, int* Count);
void Clear(int** Map, int r, int c, int* Count);
int Direction_Change(int d);

int main(void)
{
	/*
	* 📢 지역변수의 경우 소문자로 만듭니다.
	* 
	* 보통 상수의 경우 대문자로 만드는 경우가 있는데,
	* 이 또한 위의 함수처럼 convention 이므로 참고하면 더 좋을 것 같습니다.
	*/
	int N, M;   // N : 세로 칸 수, M : 가로 칸 수
	int r, c, d; // r : x 좌표, c : y 좌표, d : 현재 방향

	cin >> N >> M;
	cin >> r >> c >> d;

	// 2차원 배열 동적 할당
	int** Map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[M];
	}

	// 2차원 배열 Map 만들기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	/*
	* 🎉 문제의 요구사항에 맞는 로직처리가 아주 좋군요! 😊
	*/
	int Cleaning_Count = 0;

	bool Power_On = true;
	while (Power_On)
	{
		Cleaner_Working(Map, &r, &c, &d, &Power_On, &Cleaning_Count);
	}

	cout << Cleaning_Count << "\n";

	return 0;
}

void Cleaner_Working(int** Map, int* r, int* c, int* d, bool* flag, int* Count)
{
	int Direction_r[4] = { -1,0,1,0 }; // d - 0 :북쪽, 1 : 동쪽, 2 :남쪽, 3 : 서쪽
	int Direction_c[4] = { 0,1,0,-1 };

	Clear(Map, *r, *c, Count);

	int initial_direction = *d;
	while (true)
	{
		*d = Direction_Change(*d);
		if (Map[*r + Direction_r[*d]][*c + Direction_c[*d]] == 0)
		{
			*r += Direction_r[*d];
			*c += Direction_c[*d];
			break;
		}
		if (Direction_Change(*d + 1) == initial_direction)
		{
			if (Map[*r - Direction_r[*d]][*c - Direction_c[*d]] == 1)
			{
				*flag = false;
				break;
			}
			else
			{
				*r -= Direction_r[*d];
				*c -= Direction_c[*d];
			}
		}

	}
}

void Clear(int** Map, int r, int c, int* Count) {
	if (Map[r][c] == 0)
	{
		Map[r][c] = 2;
		*Count += 1;
	}
}

int Direction_Change(int d) {
	if (d == 0)
	{
		return 3;
	}
	else
	{
		return d - 1;
	}
}