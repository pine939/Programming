#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<vector<int> > v = {
    {},
    {1, 2, 3, 4, 5},  // 1번학생 
    {2, 1, 2, 3, 2, 4, 2, 5},  // 2번학생 
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}  // 3번학생 
};

int a[4] = {0, };
void test_print(vector<int> &v) {
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout <<endl;
}
int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> tmp_answers(answers);
    for (int i = 1; i < 4; i++) { // v[i]는 i번 학생
        cout << i << "번 학생 " << endl;
        int lcm;// i번 학생의 정답 배열의 크기와 answers 배열의 크기의 최소공배수 구하기
        lcm = (v[i].size() * answers.size())/gcd(v[i].size(), answers.size());
        cout << "lcm = " << lcm << endl; 
        // 각 배열을 최소공배수 길이만큼 늘리기
        int tmp = lcm/v[i].size();
        cout << tmp << " 만큼 늘리기" << endl;
        while((tmp-1) > 0) {
            v[i].insert(v[i].end(), v[i].begin(), v[i].end());
            tmp_answers.insert(tmp_answers.end(), tmp_answers.begin(), tmp_answers.end());
            tmp--;
        }
        cout << "학생의 늘린 배열 길이 : " << v[i].size() << endl;
        test_print(v[i]);
        cout << "정답의 늘린 배열 길이 : " << tmp_answers.size() << endl;
        test_print(tmp_answers);
        // 늘린 새로운 배열에서 같은 인덱스의 값들 빼기 
        for (int j = 0; j < tmp_answers.size(); j++) {
            v[i][j] = v[i][j] - tmp_answers[j];
            if (v[i][j] == 0) a[i]++;
        }
        
        // 0 개수 세기
    }

    // 0의 개수가 가장 많은 학생 의 인덱스 push_back
    for (int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return answer;
}

int main(void) {
    vector<int> v = {1, 3, 2, 4, 2};
    vector<int> answer;
    /*
    answer = solution(v);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    */
    for (int i = 0; i < 40/v.size(); i++) {  // 8번
        for (int j = 0; j < v.size(); j++) {  // 5번
            cout << v[j] << " ";
        // 0 1 2 3 4
        // 0 1 2 3 4
        // 0 1 2 3 4
        // .....
        }
    }
    cout << endl;
    return 0;
}