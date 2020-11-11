/*
daily review 20201111
1. STL - list //
*/

#include<iostream>
#include<list>
/*
리스트에 대한 정리
1. 시퀀스 컨테이너
2. node 기반 컨테이너
3. 이중 연결 리스트
4. vector, deque와 다르게 멤버 함수 중 정렬(sort, merge)과 이어붙이기(splice)가 있다.
5. 임의 접근 반복자([], at())은 불가하고, 양방향 반복자(++, --)를 이용해서 탐색할 수 있다.
6. push_front(), push_back(), pop_front(), pop_back() => 리스트 양 끝에서 삽입, 삭제가 가능하다.
7. insert(), erase() => 노드 중간에서 삽입, 삭제가 가능하다.
*/
using namespace std;

void list_print(list<int>& l) {
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;
}

bool predicate(int num) {
    if (num >= 100) {
        return true;
    }
    return false;
}

int main(void) {
    list<int> l;
    // push back
    cout << "push back" << endl;
    l.push_back(10);
    l.push_back(20);
    l.push_back(108);
    l.push_back(60);
    l.push_back(10);  // list는 중복 허용!
    list_print(l);

    // remove
    cout << "remove(10)" << endl;
    l.remove(10);  // 10 모두 제거
    list_print(l);

    // push front
    cout << "push front(20)" << endl;
    l.push_front(20);
    list_print(l);

    // pop front
    cout << "pop front" << endl;
    l.pop_front();
    list_print(l);

    // pop back
    cout << "pop back" << endl;
    l.pop_back();
    list_print(l);

    // remove_if
    cout << "remove_if(predicate)" << endl;
    l.remove_if(predicate);
    list_print(l);

    
}