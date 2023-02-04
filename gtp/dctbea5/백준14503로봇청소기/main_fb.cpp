#include<iostream>
using namespace std;
/*
* 🎉 define MACRO 사용 아주 좋습니다!
*/
#define MAX 50
// 청소할 방의 상태
int room[MAX][MAX];
// 로봇 청소기 위치 x, y 와 방향 d
int p_r, p_c, p_d;
// 방의 행, 열 사이즈
int r, c;
// 청소 count
int cnt = 0;
int cleaned[51][51] = {
    0,
}; //방문 시 2
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void rovot()
{
    //동서남북, 왼쪽회전 
    for (int i = 0; i < 4; i++)
    {
        int n_d = (p_d + 3 - i) % 4;
        /*
        * 🎉 4방향 탐색을 배열로 처리하신 부분 아주 좋습니다!
        */
        int n_r = p_r + dr[n_d];
        int n_c = p_c + dc[n_d];
        /*
        * 📢 제출할 땐, 주석은 제거하는 것이 좋습니다!
        */
        //cout <<n_d << "a" << n_r << endl;
        // 다음 방향 지정, 그 방향 r, c 위치 받아옴
        /*
        * 💡 n_r, n_c 값이 배열의 범위를 벗어나는 경우가 생길까요?
        * 
        * 문제에서 무조건 방의 테두리는 '1'로 감싸진다고 했습니다.
        * (지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.)
        * 
        * "n_r < 0 || n_r >= r || n_c < 0 || n_c >= c" 구문은 검사하지 않아도 되지 않을까요? 🤔
        */
        if (n_r < 0 || n_r >= r || n_c < 0 || n_c >= c || room[n_r][n_c] == 1)
        {
            continue;

        } // 그곳이 벽일 때 계속

        //벽이 아니고 아직 청소 전이라면 그 공간 청소하고 회전
        if (room[n_r][n_c] == 0 && cleaned[n_r][n_c] == 0)
        {
            cleaned[n_r][n_c] = 2; //청소 위치 확인
            p_r = n_r;
            p_c = n_c;
            p_d = n_d;
            cnt++; //청소 count up
            /*
            * 🎉 재귀(recursive)활용 너무 좋습니다!
            */
            rovot();
        }
    }
    //청소 할 곳 없거나 청소 다했으면 Back
    int back_i = p_d > 1 ? p_d - 2 : p_d + 2; // 0 -> 2, 2->0, 3->1, 1->3
    int b_r = p_r + dr[back_i];
    int b_c = p_c + dc[back_i];
    //cout <<back_i << "a" << b_r << endl;
    /*
    * 💡 b_r, b_c 값이 배열의 범위를 벗어나는 경우가 생길까요?
    */
    if (b_r >= 0 && b_r <= r || b_c >= 0 || b_c <= c)
    {
        if (room[b_r][b_c] == 0)
        {
            p_r = b_r;
            p_c = b_c;
            rovot(); //또 반복
        }

        else
        {
            //for (int i = 0; i < r; i += 1)
            //{
             //   for (int j = 0; j < c; j += 1)
             //       cout << cleaned[i][j] << " ";
            //    cout << endl;
            //} 확인
            cout << cnt << endl; //청소 카운트
            exit(0);
        }
    }

}

int main(void) {
    cin >> r >> c;
    cin >> p_r >> p_c >> p_d;

    // 방 크기 입력 및 생성
    //room = new int* [r];
    //for (int i = 0; i < c; i += 1) {
    //    room[i] = new int[c] { 0, };
   // }

    // 청소할 방 입력받기
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1)
            cin >> room[i][j];
    }
    cleaned[p_r][p_c] = 2;
    /*
    * 💡 문제의 흐름을 따라가는게 좋습니다.
    *
    * 문제에선 "로봇의 위치가 무조건 0인 상태"를 가정하지만
    * 요구사항에서는 청소하는 행위가 처음에 이뤄집니다.
    *
    * 해당 문제는 구현을 정확히 하는게 중요합니다.
    * 보통 이런 유형들은 자칫 잘 못하면 함정에 빠질 위험이 높고,
    * hidden case에서 pass하지 못하는 상황이 나올수도 있습니다.
    *
    * 로봇청소기가 cycle 후 제일 먼저 하는 행동이 청소이므로,
    * 시작할 때 cnt가 1로 시작하는 것 보다 0으로 시작하는게 좀 더 적절해 보입니다!
    */
    cnt++; //첫위치 청소
    rovot();



    return 0;
}
