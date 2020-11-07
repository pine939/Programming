#include<iostream>

using namespace std;

int dp[31];
/*
3xn 벽면을 2x1, 1x2 블록으로 채우는 방법의 수

dp[n] = 3 * dp[n-2] 
dp[n] = 3 * dp[n-2] + (2 * dp[n-4] + 2 * dp[n-6], ... , 2 * dp[0])
dp[0] = 1;
dp[1] = 0;
dp[2] = 3;
*/
int solution(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;

    if (dp[n] != 0) return dp[n];

    int tmp = 3*solution(n-2);
    for (int i = 3; i < n; i++) {
        if (i % 2 == 0) {
            tmp += 2 * solution(n-i);  // 6-4
        }
    }
    dp[n] = tmp;
    return dp[n];
}

int main(void) {
    int n;
    cin >> n;
    if (n < 1 || n > 30) return 0;

    int ret = solution(n);
    cout << ret << endl;
}