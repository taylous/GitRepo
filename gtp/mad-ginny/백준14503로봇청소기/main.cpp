// [문제] 
// 로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

// 로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 
// 1×1크기의 정사각형 칸으로 나누어져 있다.각각의 칸은 벽 또는 빈 칸이다.
// 청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다.
// 지도의 각 칸은(r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.

// 로봇 청소기는 다음과 같이 작동한다.
// 1. 현재 위치를 청소한다.
// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//    - 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//    - 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//    - 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//    - 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

// [입력]
// 첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)
// 둘째 줄에 로봇 청소기가 있는 칸의 좌표(r, c)와 바라보는 방향 d가 주어진다.
// d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.
// 셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다.
// 빈 칸은 0, 벽은 1로 주어진다.지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.
// 로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.

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
        room[i] = new int[n];
    }

    // 청소할 방 입력받기
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cin >> room[i][j];
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cout << room[i][j] << " ";
        cout << endl;
    }

    //청소한 칸 개수
    int cnt = 1;

    bool stop = true;
    while (stop) {

        int seek = 0;
        int new_rx, new_ry;
        int back_rx, back_ry;

        // 탐색(try2)
        while (seek != 15) {
            // 왼쪽 방향에 있는 칸
            if (d == 0) { new_rx = rx; new_ry = ry - 1; }
            else if (d == 1) { new_rx = rx - 1; new_ry = ry; }
            else if (d == 2) { new_rx = rx; new_ry = ry + 1; }
            else { new_rx = rx + 1; new_ry = ry; }
            d = (d + 3) % 4;  // 왼쪽 방향
            seek |= (1 << d);

            if (room[new_rx - 1][new_ry - 1] == 0) { //확인
                rx = new_rx; ry = new_ry; // 전진
                cnt += 1; //청소
                room[rx - 1][ry - 1] = 2; //청소한 곳 기록

                cout << "cleaned: (" << rx << ", " << ry << ")" << endl;
                break;
            }

        }
        if(seek == 15) {
            // 뒤쪽 칸
           if (d == 0) { back_rx = rx + 1; back_ry = ry; }
           else if (d == 1) { back_rx = rx; back_ry = ry - 1; }
           else if (d == 2) { back_rx = rx - 1; back_ry = ry; }
           else { back_rx = rx; back_ry = ry + 1; }

           // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
           if (room[back_rx - 1][back_ry - 1] != 1) {
              rx = back_rx; ry = back_ry; // 후진
              continue;
           }
           // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
           else (room[back_rx - 1][back_ry - 1] == 1) {
               stop = false;
           }
        }

        /*// 탐색(try1)
        for (int i = 0; i < 4; i += 1) {
            // 왼쪽 방향에 있는 칸
            int new_rx, new_ry;
            if (d == 0) { new_rx = rx; new_ry = ry - 1; }
            else if (d == 1) { new_rx = rx - 1; new_ry = ry; }
            else if (d == 2) { new_rx = rx; new_ry = ry + 1; }
            else { new_rx = rx + 1; new_ry = ry; }
            d = (d + 3) % 4;  // 왼쪽 방향
            // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 청소
            if (room[new_rx - 1][new_ry - 1] == 0) { //확인
                rx = new_rx; ry = new_ry; // 전진
                cnt += 1; //청소
                room[rx - 1][ry - 1] = 2; //청소한 곳 기록
                cout << "new location: (" << rx << ", " << ry << ")" << endl;
                break;
            }
            // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 다시 왼쪽부터 탐색
            else if (room[new_rx - 1][new_ry - 1] != 0) {
                fail += 1;
                continue;
            }
        }
        
        // 1) 청소하고 break  -> 다음 while loop
        // 2) 모든 방향 fail
        // 뒤쪽 칸
        int back_rx, back_ry;
        if (d == 0) { back_rx = rx + 1; back_ry = ry; }
        else if (d == 1) { back_rx = rx; back_ry = ry - 1; }
        else if (d == 2) { back_rx = rx - 1; back_ry = ry; }
        else { back_rx = rx; back_ry = ry + 1; }
        // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        if (fail == 4 && room[back_rx - 1][back_ry - 1] != 1) {
            rx = back_rx; ry = back_ry; // 후진
            continue;
        }
        // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
        if (fail == 4 && room[back_rx - 1][back_ry - 1] == 1) {
            stop = false;
        }
        */

    }

    cout << cnt << endl;

    return 0;

}