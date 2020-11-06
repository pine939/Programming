#include<iostream>
#include<vector>

using namespace std;
int main(void) {
    pair<int, int> p1;
    cout << p1.first << ' ' << p1.second << '\n'; // 0 0 출력
    p1 = make_pair(1, 2);
    cout << p1.first << ' ' << p1.second << '\n'; // 1 2 출력
    
    // pair 속에 pair를 중첩해서 사용 가능
    pair<pair<int, int>, pair<int, int>> p3 = make_pair(make_pair(1, 2), make_pair(3, 4));

    cout << p3.first.first << ' ' << p3.first.second << ' ';
    cout << p3.second.first << ' ' << p3.second.second << '\n'; // 1 2 3 4 출력

    return 0;
}