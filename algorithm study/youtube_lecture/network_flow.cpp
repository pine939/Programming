#include <iostream>
#include <vector> // 정점과 간선
#include <queue> // BFS

#define MAX 100
#define INF 100000000

using namespace std;

int n = 6; result;
int c[MAX][MAX], f[MAX][MAX], d[MAX]; // capacity, flow, 방문했는지
vector<int> a[MAX];

void max_flow(int start, int end) {
	while(1) {
		fill(d, d+MAX, -1); // 방문하지 않은 정점은 -1로 초기화q
		queue<int> q;
		q.push(start);
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i <a[i].size; i++) {
				int y = a[x][i];
				//방문하지 않은 노드 중에서 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] != -1) {
					q.push(y);
					d[y] = x; // 경로를 기억합니다.
					if (y == end) break; // 도착지에 도달한 경우
				}
			}
		}
		// 모든 경로를 다 탐색한 경우 탈출합니다.
		if (d[end] == -1) break;
		// 이제 최소 유량을 탐색합니다.
		// 거꾸로 최소 유량을 탐색합니다.
		int flow = INF;
		for (int i = end; i != start; i = d[i]) { // d[i]는 이전꺼
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// 최소 유량만큼 추가합니다.
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;

	}
}


int main(void) {
	a[1].push_back(2);
	a[2].push_back(1); // 음의 유량 확인을 위함
	c[1][2] = 12;
	...
	max_flow(1, 6);
}
