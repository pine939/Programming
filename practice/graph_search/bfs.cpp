#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool visited[11];
vector<int> graph[11];


void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();  // pop될 때 탐색 되었음을 의미
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];
			if (visited[nxt] == false) {
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
}

int main() {
	// make graph
	graph[1].push_back(2);
	graph[1].push_back(5);
	graph[1].push_back(9);

	graph[2].push_back(1);
	graph[2].push_back(3);

	graph[3].push_back(2);
	graph[3].push_back(4);

	graph[4].push_back(3);

	graph[5].push_back(1);
	graph[5].push_back(6);
	graph[5].push_back(8);

	graph[6].push_back(5);
	graph[6].push_back(7);

	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(5);
	graph[8].push_back(7);

	graph[9].push_back(1);
	graph[9].push_back(10);

	graph[10].push_back(9);

	bfs(1);
	return 0;
}
