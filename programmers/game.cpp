#include<iostream>

using namespace std;
/*
  0
3   1
  2
--------
0 = 육지
1 = 바다
*/
int map[50][50] = {0, };
int g_dir[4] = {3, 0, 1, 2}; // turn left 방향
// 왼쪽으로 방향을 틀었을 때 이동 방법 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int rdx[4] = {0, -1, 0, 1};
int rdy[4] = {1, 0, -1, 0};
int N, M;
int result_count = 0;
void solution(int mx, int my, int md) { // (mx, my)에서 md방향으로 서있다.
    // 1. 왼쪽 방향으로 회전하면서 갈 곳을 정한다.
    // 2-1. 왼쪽 방향 칸이 방문하지 않은 곳이라면 그 방향으로 1 전진한다.
    // 2-2. 방문하지 않은 칸이 없다면 회전한 채로 둔다. 그리고 1단계로...
    // 3-1. 네 방향 모두 가본 칸인 경우 방향은 그대로 위치는 1 후퇴한다. 그리고 1단계로...
    // 3-2. 뒤로 가야 하는 칸이 바다라면 멈춘다. 여기서 끝!!!

    int check = 2;
    // map을 벗어난 경우
    if (mx < 1 || mx > 50 || my < 1 || my > 50) {
        return;
    }

    // 무조건 바다
    if (mx == 0 || mx == (N-1) || my == 0 || my == (M-1)) {
        // md는 그대로, 뒤로 움직임 
        mx += rdx[md];
        my += rdy[md];
        map[mx][my];
        // 뒤가 바다인 경우 종료...
    }

    check = map[mx + dx[g_dir[md]]][my + dy[g_dir[md]]];
    if (check = -1) { // 이동할 곳을 이미 방문했다면
        if (map[mx][my] == 0) { // 현재 육지라면
            map[mx][my] = -1; // 현재 위치 방문 도장
            result_count++;
        }
        solution(mx, my, g_dir[md]); // 다시 왼쪽으로 회전한다.
    } else if (check == 0) { // 육지인 경우
        // move
        mx += dx[g_dir[md]];
        my += dy[g_dir[md]];
        map[mx][my] = -1; // check visited
        result_count++;
        solution(mx, my, g_dir[md]);
    } else if (check == 1) {
        
    }
}

void solution2(int mx, int my, int md) {
    int next_mx, next_my, next_md;
    // 범위 밖
    if (mx < 1 || mx > 50 || my < 1 || my > 50) {
        return;
    }

    // 육지
    if (map[mx][my] == 0) {
        map[mx][my] = -1;  // 방문 표시
        result_count++;
        md = g_dir[md];  // 왼쪽 회전
        mx += dx[md];
        my += dy[md];
        
        next_mx = mx + dx[md];
        next_my = my + dy[md];
        map[next_mx][next_my];
    }

    // 바다
    if (map[mx][my] == 1) {
        // 뒤로 이동
        mx += rdx[md];
        my += rdy[md];
    }

    solution2(mx, my, md);
}

int main(void) {
    int my_x, my_y, my_dir;
    cin >> N >> M;
    if (N < 3 || M > 50) return 0;

    cin >> my_x >> my_y >> my_dir;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    //solution(my_x, my_y, my_dir);
    solution2(my_x, my_y, my_dir);
    cout << result_count << endl;
}