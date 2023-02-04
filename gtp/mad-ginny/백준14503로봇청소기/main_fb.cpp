#include<iostream>
using namespace std;

int main(void) {

    int** room;
    int rx, ry, d;
    int n, m;

    cin >> n >> m;
    cin >> rx >> ry >> d;

    room = new int* [n];
    for (int i = 0; i < n; i += 1) {
        room[i] = new int[n];
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cin >> room[i][j];
    }

    /*
    * 💡 중간과정이나 결과를 출력하는 부분은 따로 함수를 만드는게 좋습니다.
    * 
    * 아무래도 만들다 보면 디버깅 용도로 출력하는 코드가 생기는데,
    * 중간마다 넣어두게 되면 나중에 주석/제거 하는 과정에서 문제가 발생할 수 있습니다.
    * 그러므로 따로 함수를 만들어두고 호출하거나 되도록이면,
    * Visual Studio의 debug를 사용하는게 좋습니다.
    * 
    *   ex:
            void print() { 
                for (int i = 0; i < n; i += 1) {
                    for (int j = 0; j < m; j += 1)
                        cout << room[i][j] << " ";
                    cout << endl;
                }
            }
            
            int main(void) {
                ... 생략 ...
                print();
            }
    * 
    */
    /*for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cout << room[i][j] << " ";
        cout << endl;
    }*/

    //청소한 칸 개수
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
    int cnt = 1;

    bool stop = true;
    while (stop) {

        /*
        * 💡 지역변수로 계속 memory 할당/초기화 되고 있습니다.
        * 
        * local variable(지역변수)는 block scope(block = {}, scope = 범위)을 가지는데,
        * int variable = 0 과 같이 선언하면 메모리 할당과 초기화를 하게 됩니다.
        * 
        * 지금 로직의 경우 while문에서 반복적으로 할당/초기화가 이루어지기 때문에,
        * 성능상에서 안 좋은 영향을 미칩니다.
        * 
        * 해당 변수들은 반복문 밖에서 한 번 선언하고 반복문 안에서 초기화만 해주도록 하여,
        * 계속 메모리에 할당되지 않도록 방지하면 더 좋습니다.
        */
        int seek = 0;
        int new_rx, new_ry;
        int back_rx, back_ry;

        // 탐색(try2)
        while (seek != 15) {
            // 왼쪽 방향에 있는 칸
            /*
            * 💡 4방향 탐색은 반복문으로 하면 더 깔끔하고 보기 쉽게 수정할 수 있습니다.
            * 
            * <전역변수>
            * int loX[] = { -1, 0, 1, 0 };
            * int loY[] = { 0, 1, 0, -1 };
            * 
            * ...생략...
            * for (int i = 0; i < 4; i += 1) {
            *   int new_rx = rx + loX[i];
            *   int new_ry = ry + loY[i];
            * }
            * ...생략...
            */
            if (d == 0) { new_rx = rx; new_ry = ry - 1; }
            else if (d == 1) { new_rx = rx - 1; new_ry = ry; }
            else if (d == 2) { new_rx = rx; new_ry = ry + 1; }
            else { new_rx = rx + 1; new_ry = ry; }
            d = (d + 3) % 4;  // 왼쪽 방향
            /*
            * 📢 bit 비교 할 때, 만약 해당 값이 '1'bit 라면 0 이상의 값이 반환됩니다.
            * 
            * 즉 int value = 2; 라면,
            * value |= (1 << 1) 했을 때 반환되는 값이
            * '1' 아니라 '2' 입니다. (2^1 = 2)
            */
            seek |= (1 << d);

            if (room[new_rx - 1][new_ry - 1] == 0) { //확인
                rx = new_rx; ry = new_ry; // 전진
                cnt += 1; //청소
                room[rx - 1][ry - 1] = 2; //청소한 곳 기록

                cout << "cleaned: (" << rx << ", " << ry << ")" << endl;
                break;
            }

        }
        if (seek == 15) {
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
            /*
            * 📢 else if 를 써야하는거 아닐까요?! 🤔
            */
            else (room[back_rx - 1][back_ry - 1] == 1) {
                stop = false;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}