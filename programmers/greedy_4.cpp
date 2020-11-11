#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
오름차순 정렬
최소값 + 최대값이 limit보다 작으면 answer--
*/
int solution(vector<int> people, int limit) {
    int answer = people.size();
    sort(people.begin(), people.end());
    int pstart = 0, pend = people.size() -1;

    for (;pstart < pend; --pend) {
        if (people[pstart] + people[pend] <= limit) {
            pstart++;
            answer--;
        }
    }
    return answer;
}

int main(void) {
    int n, l, w;
    vector<int> v;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> w;
        v.push_back(w);
    }

    int ret = solution(v, l);
    cout << ret << endl;
}
/*
solution : 직관적, 정확하지만 효율성점수 낮음
1. people 을 sort
2. people size == 0이 될때까지
  2.1 top, pop
  2.2 limit - top = remain
  2.3 people에서 remain보다 작은 원소가 있다면 이 또한 pop 그리고 answer++
      people에서 remain보다 작은 원소가 없다면 pop하지 않고 answer++
*/
/*
int solution(vector<int> people, int limit) {
    int answer = 0;
    int data, remain = 0;
    int find_flag = 0;
    sort(people.begin(), people.end(), greater<int>());
    while(people.size() != 0) {
        data = people[0]; // max
        people.erase(people.begin());
        remain = limit - data;
        for (int i = 0; i < people.size(); i++) {
            if (people[i] <= remain) {
                people.erase(people.begin() + i);
                break;
            }
        }
        answer++;
    }
    return answer;
}
*/

/*
효율성 통과했으나 예외 케이스 존재
people = [1,2,3,4]
limit = 5인 경우
정답은 2지만 3이 출력됨
*/
/*
int solution(vector<int> people, int limit) {
    int answer = people.size();
    int min_sum = 0;
    int people_num = people.size();
    sort(people.begin(), people.end());


   if ((people.size() % 2) != 0) {
       people_num--;
   }

   for (int i = 0; i <= people_num/2; i+=2) {
       min_sum = people[i] + people[i+1];
       if (min_sum <= limit) {
           answer--;
       }
   }
    return answer;
}
*/


