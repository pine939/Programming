#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tot = brown + yellow;  // 총 벽돌의 개수
    int s, r;
    vector<pair<int, int> > v;  // return 후보
    for (int i = 3; i <= tot; i++) {
        s = tot / i;
        r = tot % i;
        if (r == 0 && s >=3 && i >= 3 && i <= s) {  // s가로 i세로
            v.push_back(make_pair(s, i));
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int brown_num = 2 * v[i].first + 2 * (v[i].second - 2);
        if ((tot - brown_num) == yellow) {
            answer.push_back(v[i].first);
            answer.push_back(v[i].second);
            break;
        }
    }

    return answer;
}

int main(void) {
    int brown, yellow;  // 가로, 세로
    vector<int> answer;
    cin >> brown >> yellow;
    answer = solution(brown, yellow);

    cout << answer[0] << ", " << answer[1] << endl;
}