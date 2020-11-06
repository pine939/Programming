#include<iostream>
#include<map>

using namespace std;

int main(void) {
    map<int, int> m;

    // pair 객체 insert()
    m.insert(pair<int, int> (5, 100));
    m.insert(pair<int, int> (3, 100));
    pair<int, int> p(9, 50);
    m.insert(p);

    // [] 연산자로 key/value 삽입
    m[11] = 200;
    m[12] = 200;
    m[13] = 40;

    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        cout << "<" << (*it).first << ", " << (*it).second << "> ";
        cout << endl;
        // 출력 
        // <3, 100>, <5, 100>, <9, 50>, <11, 200>, <12, 200>, <13, 40>
    }

    // [] 연산자로 key/value 갱신 가능
    m[13] = 140;

    pair<map<int, int>::iterator, bool> pr;

    // 중복 데이터 삽입 불가
    pr = m.insert(pair<int, int>(10, 30));
    if (true == pr.second) {
        cout << "key : " << pr.first->first << ", value : " << pr.first->second << " 저장 완료!" << endl;
    } else {
        cout << "key 10이 이미 m에 있습니다." << endl;
    }
    return 0;
}