#include<stdio.h>
#include<stdint.h>
/*
dynamic programming 
하나의 문제는 단 한 번의 계산으로 해결한다.
1) 분할정복
2) 메모이제이션

*/

uint64_t dp[51];
uint64_t fibo(int n) {
    // fibo(n) = fibo(n-1) + fibo(n-2)
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (!dp[n]) {
        dp[n] = fibo(n-1) + fibo(n-2); 
        return dp[n];
    }
    return dp[n];
}

int main(void) {
    int n;
    uint64_t ret;
    scanf("%d", &n); // 1 ~50 자연수
    if (n < 1 || n > 50) return 0;
    ret = fibo(n);
    printf("%d's fibo is %llu\n", n, ret);
}