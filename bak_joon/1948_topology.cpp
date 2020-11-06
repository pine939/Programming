// 임계경로와 임계경로에 속해 있는 모든 정점의 개수 구하기

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge {
	public:
		int node;
		int time;
		Edge(int node, int time) {
			this->node = node;
			this->time = time;
		}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX]; // 임계경로 처리는 한번씩만 한다.(check)
vector<Edge> a[MAX];
vector<Edge> b[MAX]; // 역추적

void topology_sort() {
	queue<int> q;
	// 시작점 노드를 큐에 삽입합니다.
	q.push(start);
	// 더 이상 방문할 노드가 없을 때까지 반복합니다.
	while(!q.empty()) { // 정점을 큐에서 꺼내어 정점에 연결된 모든 노드들을 처리합니다.
		int x = q.front();
		q.pop();
		for(int i = 0; i < a.[i].size;i ++) {
			Edge y = Edge(a[x][i].node, a[x][i].time); 
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
			if(--inDegree[y.node] == 0) {
				q.push(y.node);
			}
		}
	}
	// 결과를 역추적합니다.
	int count = 0; // 임계경로에 속한 모든 정점의 개수
	q.push(finish);
	while(!q.empty()) {
		int y = q.front();
		q.pop();
		for(int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			// 최장 경로(임계경로)에 포함되는 간선인지 확인한다.
			if(result[y] - result[x.node] == x.time) {
				count++;
				// 큐에는 한 번씩 담아 추적합니다.
				if(c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	printf("%d\n%d", result[finish], count);
}

int main(void) {
	int n, m;
	scanf("%d", &n, &m);
	for(int i=0;i<m;i++){
		int x, node, time;//시작점, 도착점, 간선의 비용
		scanf("%d %d %d", &x, &node, &time);
		a[x].push_back(Edge(node, time));
		b[node].push_back(Edge(x,time));
		inDegree[node]++;
	}

	scanf("%d %d", &start, &fin);

}
