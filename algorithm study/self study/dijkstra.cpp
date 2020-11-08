#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define INF 987654321
#define VERTEX_MAX 6
vector<pair<int, int> > a[VERTEX_MAX+1];  // 간선 정보
int visited[VERTEX_MAX+1];  // 방문 정보
int d[VERTEX_MAX+1];  // 최소 비용 정보

/*
다익스트라 알고리즘
- 특정 노드에서 모든 정점으로 갈 때의 최소 비용을 구한다.

d[7]을 구하는 함수 
1) d[start] = 0 
2) pair(d[start], 0)을 우선순위 큐에 넣는다.
3) 우선순위 큐에서 pop (최소 비용 가져오기)
4) 현재(d)의 거리 보다 pop한 값이 길면 skip 
5) 인접한 노드들 검사해서 최소비용을 구한다. 
6) 기존의 최소비용보다 저렴하다면 교체 후 큐에 넣는다.
*/
void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;  // first : 정점, second : 최소비용
    d[start] = 0;
    pq.push(make_pair(start, 0));

    while(!pq.empty()) {
        // pop
        int pq_v = pq.top().first;
        int pq_d = -pq.top().second;
        pq.pop();
        if (d[pq_v] < pq_d) continue;

        // pq_v는 선택된 노드
        // 선택된 노드의 인접노드를 확인
        for (int i = 0; i < a[pq_v].size(); i++) {
            int next = a[pq_v][i].first;
            int next_d = pq_d + a[pq_v][i].second;
            if (next_d < d[next]) {
                // change
                d[next] = next_d;
                pq.push(make_pair(next, -next_d));
            }
        }
    }
}
int main(void) {
    for (int i = 1; i <= VERTEX_MAX; i++) {
        d[i] = INF;
    }
    a[1].push_back(make_pair(2,2));
    a[1].push_back(make_pair(3,5));
    a[1].push_back(make_pair(4,1));

    a[2].push_back(make_pair(1,2));
    a[2].push_back(make_pair(3,3));
    a[2].push_back(make_pair(4,2));

    a[3].push_back(make_pair(1,5));
    a[3].push_back(make_pair(2,3));
    a[3].push_back(make_pair(4,3));
    a[3].push_back(make_pair(5,1));
    a[3].push_back(make_pair(6,5));

    a[4].push_back(make_pair(1,1));
    a[4].push_back(make_pair(2,2));
    a[4].push_back(make_pair(3,3));
    a[4].push_back(make_pair(5,1));

    a[5].push_back(make_pair(3,1));
    a[5].push_back(make_pair(4,1));
    a[5].push_back(make_pair(6,2));

    a[6].push_back(make_pair(3,5));
    a[6].push_back(make_pair(5,2));

    dijkstra(1);

    // 결과 출력
    for (int i = 1; i <= VERTEX_MAX; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}