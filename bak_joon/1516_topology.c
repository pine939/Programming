/* 
   위상정렬 알고리즘 
   1. 진입차수가 0인 정점을 큐에 넣는다.
   2. 큐에서 pop하고 그 정점에 연결된 간선을 삭제하고, 간선과 연결된 정점의 진입차수를 -1한다.
   ...
 */

#include<iostream>
#include<vector>
#include<queue>
#define MAX 501 //건물의 개수

using namespace std;

int n, inDegree[MAX], time[MAX], result[MAX];
vector<int> a[MAX];

void topology_sort() {
	queue<int> q;
	// 진입 차수가 0인 노드를 큐에 삽입합니다.
	for(int i = 1; i <= n; i++) {
		if(inDegree[i] == 0) {
			result[i] = time[i]; // 맨 처음 건물을 지을 수 있는 최소 시간
			q.push(i);
		}

	}
	// 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
	for(int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		// result[i] = x; // 큐에서 꺼낸 순서가 위상정렬 순서가 됩니다.
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			result[y] = max(result[y], result[x] + time[y]); // 임계경로
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
			if(--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", result[i]);
	}
}

int main(void) {
	int m;
	scanf("%d", &n);
	for(int i = 0; i < m; i++) {
		scanf("%d", &time[i]);
		while(1) {
			int x;
			scanf("%d", &x);
			if(x == -1) break;
			inDegree[i]++;
			a[i].push_back(i);
		}
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++;
	}
	topology_sort();
}
