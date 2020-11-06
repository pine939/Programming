#include<iostream>
#include<vector>

using namespace std;
// 1부터 n까지 합을 반환한다.
int fast_sum(int n) {
    if (n == 1) return 1;

    // 홀수인 경우 재귀호출로 해결
    if (n % 2 == 1) {
        return n + fast_sum(n-1);
    }

    return (2*fast_sum(n/2) + (n/2)*(n/2));
}

////////

class square_matrix;  // 정방행렬을 반환하는 클래스
square_matrix identity(int n);  // n*n크기의 항등행렬(identity matrix)을 반환하는 함수
/*
square_matrix pow(const square_matrix& A, int m) {
    if (m == 0) {
        return identity(A.size());
    }

    if (m %2 > 0) {
        return pow(A, m-1)*A;
    }
    square_matrix half = pow(A, 2/m);
    return half * half;
}
*/

/////////

// 큰 두 수를 곱하는 알고리즘 O(n^2)
/*
void normalize(const vector<int>& num) {  // num[]의 자릿수 올림을 처리한다.
    num.push_back(0);
    for(int i = 0; i+1 < num.size(); ++i) {
        if(num[i] < 0) {
            int borrow = (abs(num[i])+9)/10;
            num[i+1] -= borrow;
            num[i] += borrow *10;
        } else {
            num[i+1] += num[i]/10;
            num[i] % 10;
        }
    }
    while(num.size() > 1 && num.back() == 0){
        num.pop_back();
    }
} 

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size()+b.size()+1, 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[i];
        }
    }
    normalize(c);
    return c;
}
*/