#include<iostream>
#include<stdint.h>
using namespace std;

uint64_t dp[1000001][2];
uint64_t solution(int n) {
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 2;
    dp[1][1] = 0;
    dp[2][0] = 7;
    dp[2][1] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i][1] = (dp[i-1][1] + dp[i-3][0]) % 1000000007;
        dp[i][0] = (2 * dp[i-1][0] + 3 * dp[i-2][0] + 2 * dp[i][1]) % 1000000007;
    }

    return dp[n][0];
}
int main(void) {
    int n;
    cin >> n;
    if (n < 1 || n > 1000000) return 0;
    uint64_t ret = solution(n);
    cout << ret << endl;  
}