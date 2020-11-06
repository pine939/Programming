#incude<iostream>
#include<vector>

using namespace std;
int main(void) {
    vector<int> v1;
    vector<int> v2(6, 1);
    vector<int> v3 = {1, 2, 3, 4, 5};

    // .push_back()을 사용하면 가장 뒤에 데이터를 추가할 수 있다.
    vector<int> a = {1, 2, 3, 4, 5};
    a.push_back(6); // {1, 2, 3, 4, 5, 6}
    a.push_back(7); // {1, 2, 3, 4, 5, 6, 7}

    // .pop_back()은 가장 뒤의 데이터를 꺼내온다.
    a.pop_back(); // {1, 2, 3, 4, 5, 6}

    // 배열 비우기
    a.clear();

    // 배열의 길이. 주로 루프 돌릴 때 유용
    a.size();

    // 배열처럼 인덱스를 사용해서 자료 접근 가능
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }

    // a.begin(), a.end()를 입력하면 iterator가 반환된다.
    // sort 라이브러리 쓸때 유용
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}