#include<iostream>
#include<string>
#include<stdint.h>
/*
복습
아이디어는 빨리 떠올렸지만 구현에서 시간이 걸렸던 문제
1. answer.appned(max)
2. char형식을 int로 변환 빠르게 --> number[j] - '0'
*/

using namespace std;
string solution(string number, int k) {
    string answer = "";
    uint64_t number_size = number.size();
    uint64_t ret_size = number_size - k;

    // number[0] ~ number[k+0] 에서 top0과 인덱스를 구한다.
    // number[이전에구한 인덱스 + 1] ~ number[k + i]에서 top i와 인덱스를 구한다.
    
    int max = -1;
    uint64_t i = 0, j = 0, tmp_idx = 0, max_idx = -1;
    for (i = 0; i < ret_size; i++) {  // 0 ~ 5 (6번 반복)
        for (j = max_idx+1; j <= (k + i); j++) {  // 0 ~ 3인덱스에서 최대값 및 인덱스 구함
            if (max < (number[j] - '0')) {
                max = (number[j] - '0');  // 범위 내 최댓값
                tmp_idx = j;
            }
        }
        answer.append(to_string(max));
        max_idx = tmp_idx;  // 범위 내 최댓값 인덱스
        //cout << "MAX:" << max << ", MAX IDX : " << max_idx << endl;
        max = -1;
    }
    return answer;

}

int main(void) {
    string number;
    int k;
    cin >> number >> k;
    if (number.size() < 1 || number.size() > 1000000) return 0;

    string result = solution(number, k);
    cout << result << endl;
}

/*
기초지식 
1. int to string
 1) to_string 함수 사용
 2) stringstream 라이브러리 사용

2. string to int
 1) stoi 함수 사용
 2) stringstream 라이브러리 사용
*/

