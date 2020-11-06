// 6장. 재귀호출 

// 1부터 n까지 합을 반환한다. 
int sum (int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += i;
    }     
    return ret;
}

// 1부터 n까지 합을 반환한다.
int recursive_sum(int n) {
    if (n == 1) {  // 기저조건 (더 이상 쪼개지지 않을 때)
        return 1;
    }
    return n + recursive_sum(n-1);
}