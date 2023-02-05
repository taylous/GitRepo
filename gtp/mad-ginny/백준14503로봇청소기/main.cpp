#include<iostream>
using namespace std;

int main(void) {

    // 청소할 방의 상태
    int** room;
    // 로봇 청소기 위치 x, y 와 방향 d
    int rx, ry, d;
    // 방의 행, 열 사이즈
    int n, m;

    cin >> n >> m;
    cin >> rx >> ry >> d;

    // 방 크기 입력 및 생성
    room = new int* [n];
    for (int i = 0; i < n; i += 1) {
        room[i] = new int[m];
    }

    // 청소할 방 입력받기
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cin >> room[i][j];
    }

    //청소한 칸 개수
    int cnt = 0;

    int seek = 0;
    int new_rx = rx; int new_ry = ry;
    int back_rx, back_ry;

    while (true) {

        if (room[rx][ry] == 0) { //확인
            cnt += 1; //청소
            room[rx][ry] = 2; //청소한 곳 기록
        }

        seek = 0;

        // 탐색(try2)
        while (seek != 15) {
            // 왼쪽 방향에 있는 칸
            d = (d + 3) % 4;  // 왼쪽 방향

            if (d == 0) { new_rx = rx - 1; }
            else if (d == 1) { new_ry = ry + 1; }
            else if (d == 2) { new_rx = rx + 1; }
            else { new_ry = rx - 1; }

            if (room[new_rx][new_ry] == 0) {
                break;
            }
            seek |= (1 << d);
        }

        if (seek == 15) {
            // 뒤쪽 칸
            if (d == 0) { back_rx = rx + 1; back_ry = ry; }
            else if (d == 1) { back_rx = rx; back_ry = ry - 1; }
            else if (d == 2) { back_rx = rx - 1; back_ry = ry; }
            else { back_rx = rx; back_ry = ry + 1; }

            // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
            if (room[back_rx][back_ry] == 1) {
                break;
            }
            // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
            rx = back_rx; ry = back_ry; // 후진
        }
        else {
            rx = new_rx; ry = new_ry;
        }

    }

    cout >> cnt >> endl;
    return 0;

}