#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void test_print(vector<int> &v) {
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout <<endl;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // lost와 reserve에서 겹치는 번호 0으로 초기화
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve[i] = 0;
                lost[j] = 0;
            }
        }
    }
    
    // 정렬
    sort(lost.begin(), lost.end(), greater<int>());
    sort(reserve.begin(), reserve.end(), greater<int>());

    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 0) {
            // i 부터 끝까지 배열 자른다.
            lost.erase(lost.begin()+i, lost.end());
        }
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] == 0) {
            // i 부터 끝까지 배열 자른다.
            reserve.erase(reserve.begin()+i, reserve.end());
        }
    }

    // reserve:{3}  lost:{4, 2} 
    vector<int> tmp1(lost);
    vector<int> tmpr1(reserve);
    for(int i = 0; i < tmpr1.size(); i++) {
        for (int j = 0; j < tmp1.size(); j++) {
            if (tmp1[j] == 0 || tmpr1[i] == 0) continue;
            if (((tmpr1[i] - tmp1[j]) == 1) || ((tmp1[j] - tmpr1[i]) == 1)) {
                tmp1[j] = 0;
                tmpr1[i] = 0;
                break;
            }
        }
    }

    // reserve:{3} lost:{4, 2}
    vector<int> tmp2(lost);
    vector<int> tmpr2(reserve);
    for (int i = (tmpr2.size() - 1); i >= 0; i--) {
        for (int j = 0; j < tmp2.size(); j++) {
            if (tmp2[j] == 0 || tmpr2[i] == 0) continue;
            if (((tmpr2[i] - tmp2[j]) == 1) || ((tmp2[j] - tmpr2[i]) == 1)) {
                tmp2[j] = 0;
                tmpr2[i] = 0;
                break;
            }
        }
    }

    sort(tmp1.begin(), tmp1.end(), greater<int>());
    sort(tmp2.begin(), tmp2.end(), greater<int>());
    for (int i = 0; i < tmp1.size(); i++) {
        if (tmp1[i] == 0) {
            // i 부터 끝까지 배열 자른다.
            tmp1.erase(tmp1.begin()+i, tmp1.end());
        }
    }

    for (int i = 0; i < tmp2.size(); i++) {
        if (tmp2[i] == 0) {
            // i 부터 끝까지 배열 자른다.
            tmp2.erase(tmp2.begin()+i, tmp2.end());
        }
    }

    if (tmp1.size() > tmp2.size()) {
        answer = n - tmp2.size();
    } else {
        answer = n - tmp1.size();
    }

    return answer;
}

int main(void) {
    vector<int> v1;
    //v1.push_back(2);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(1);
    //v2.push_back(3);
    //v2.push_back(5);
    cout << solution(3, v1, v2) << endl;
}