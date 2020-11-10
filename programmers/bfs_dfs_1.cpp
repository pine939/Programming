#include<iostream>
#include<vector>

using namespace std;
/*
정답을 참고한 문제...
*/
int answer;
void bfs(vector<int> &numbers, int target, int cnt = 0, int sum = 0) {
    if (cnt == numbers.size() -1) {
        if (target == (sum + numbers[cnt])) answer++;
        if (target == (sum - numbers[cnt])) answer++;
        return;
    }

    bfs(numbers, target, cnt+1, sum+numbers[cnt]);
    bfs(numbers, target, cnt+1, sum-numbers[cnt]);
}

int solution(vector<int> numbers, int target) {
    bfs(numbers, target);
    return answer;
}

int main(void) {
    vector<int> n;
    n.push_back(1);
    n.push_back(1);
    n.push_back(1);
    n.push_back(1);
    n.push_back(1);

    int ret = solution(n, 3);
    cout << ret << endl;
    return 0;
}

    /*
    int answer = 0;
    vector<int> reverse_numbers;
    for (int i = 0; i < numbers.size(); i++) {
        reverse_numbers.push_back((-1) * numbers[i]);
    }

    int n = 1, sum;
    while (n <= numbers.size()) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        for (int i = n; i < reverse_numbers.size(); i++) {
            sum += reverse_numbers[i];
        }
        if (sum == target) {
            answer++;
            break;
        }
        n++;
    }
    */