#include<iostream>
#include<set>

using namespace std;
int main(void) {
    set<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(60);

    set<int>::iterator it;

    s.insert(10); // 중복 불가!!!

    for(it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' '; // 10 20 30 40 50 60 출력
    }

    // 값 존재 여부 확인
    it = s.find(30);
    if (it != s.end()) {
        cout << *it << " 존재" << endl;
    } else {
        cout << "존재하지 않음" << endl;
    }

    return 0;
}