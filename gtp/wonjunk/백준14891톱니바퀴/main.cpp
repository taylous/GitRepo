#include <iostream>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

struct Direction
{
	int WheelNum;
	int RotateDirection;
};

void InputDirectionInformation(Direction* arr, int K);
void InputWheelInformation(int* arr);
void solve(int* arrW, Direction* arrd, int iter, int* Score);
void play(int* WheelInformation, Direction RotateInformation);
bool Check(int* WheelInformation, Direction RotateInformation, int NearWheel, Direction* push);
void CheckNearBy(int* WheelInformation, Direction RotateInformation, queue<Direction>* Play_Queue, bool* CheckArr);
void rotate(int* WheelInformation, int WheelNum, int Direction, bool* CheckArr);
int GetScore(int* WheelInformation);

int main(void)
{
	int K;
	int Wheel[4] = { 0 };
	int Score;

	InputWheelInformation(Wheel);

	cin >> K;
	Direction *DirectionArr = new Direction[K];
	InputDirectionInformation(DirectionArr, K);

	solve(Wheel, DirectionArr, K, &Score);

	cout << Score;

	return 0;
}

void InputWheelInformation(int* arr)
{
	string input;
	int Wheel_Information;
	int num;
	for (int i = 0; i < 4; i++)
	{
		num = 1;
		Wheel_Information = 0;
		cin >> input;
		for (int j = 0; j < 8 ; j ++)
		{
			Wheel_Information += ((int)input[j] - 48) * num;
			num = num * 2;
		}
		arr[i] = Wheel_Information;
	}
}

void InputDirectionInformation(Direction* arr, int K)
{
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i].WheelNum >> arr[i].RotateDirection;
		arr[i].WheelNum -= 1;
	}
}

void solve(int* arrW, Direction* arrd, int iter, int* Score)
{
	for (int i = 0; i < iter; i++)
	{
		play(arrW, arrd[i]);
	}

	*Score = GetScore(arrW);
}

void play(int* WheelInformation, Direction RotateInformation)
{

	queue<Direction> Play_Queue;
	bool checkArr[4] = { false, false, false, false };
	checkArr[RotateInformation.WheelNum] = true;
	bool flag = true;
	int WheelNum = RotateInformation.WheelNum;
	int RotateDirection = RotateInformation.RotateDirection;
	Direction now_d = { WheelNum, RotateDirection };

	Play_Queue.push(now_d);
	while (!Play_Queue.empty())
	{
		now_d = Play_Queue.front();
		CheckNearBy(WheelInformation, now_d, &Play_Queue, checkArr);
		rotate(WheelInformation, now_d.WheelNum, now_d.RotateDirection, checkArr);
		Play_Queue.pop();;
	}
}

void rotate(int* WheelInformation, int WheelNum, int Direction, bool* CheckArr)
{
	CheckArr[WheelNum] = true;
	bool flag = false;
	if (Direction == 1)
	{
		flag = (WheelInformation[WheelNum] & (1 << 7)) == 128;
		WheelInformation[WheelNum] = (WheelInformation[WheelNum] << 1) & 255;
		if (flag)
		{
			WheelInformation[WheelNum] += 1;
		}
	}
	else
	{
		flag = (WheelInformation[WheelNum] & 1) == 1;
		WheelInformation[WheelNum] = (WheelInformation[WheelNum] >> 1) & 255;
		if (flag)
		{
			WheelInformation[WheelNum] += 128;
		}
	}
}

void CheckNearBy(int* WheelInformation, Direction RotateInformation, queue<Direction>* Play_Queue, bool* CheckArr)
{
	int num[2] = { RotateInformation.WheelNum + 1,
				   RotateInformation.WheelNum - 1 }; // 0 : 오른쪽 톱니바퀴, 1 : 왼쪽 톱니바퀴

	Direction push_struct;

	for (int i = 0; i < 2; i++)
	{
		if (num[i] >= 0 && num[i] < 4)
		{
			if (CheckArr[num[i]] == false && Check(WheelInformation, RotateInformation, num[i], &push_struct))
			{
				Play_Queue->push(push_struct);
			}
		}
	}
}

bool Check(int* WheelInformation, Direction RotateInformation, int NearWheel, Direction* push)
{
	Direction push_d = { NearWheel, RotateInformation.RotateDirection * -1 };
	int Now_Check_Num = WheelInformation[RotateInformation.WheelNum];
	int Near_Check_Num = WheelInformation[NearWheel];

	if (RotateInformation.WheelNum > NearWheel)
	{
		Now_Check_Num = ((Now_Check_Num & (1 << 6)) >> 6) & 1;
		Near_Check_Num = ((Near_Check_Num & (1<< 2)) >> 2) & 1;
	}
	else
	{
		Now_Check_Num = ((Now_Check_Num & (1 << 2)) >> 2) & 1;
		Near_Check_Num = ((Near_Check_Num & (1 << 6)) >> 6) & 1;
	}

	if ((Now_Check_Num ^ Near_Check_Num) == 1)
	{
		*push = push_d;
		return true;
	}
}

int GetScore(int* WheelInformation)
{
	int Score = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((WheelInformation[i] & 1) == 1)
		{
			Score += (int)pow(2, i);
		}
	}

	return Score;
}