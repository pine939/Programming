#include<iostream>

using namespace std;

int dp[1001];
int solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;

    if (dp[n] == 0) {
        dp[n] = (solution(n-1) + 2*solution(n-2)) % 10007;
    }
    return dp[n];
}
int main(void) {
    int n;
    cin >> n;
    if (n < 1 || n > 1000) return 0;

    int ret = solution(n);
    cout << ret << endl;
}