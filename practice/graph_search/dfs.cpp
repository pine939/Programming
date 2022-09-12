#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool visited[11];
vector<int> graph[11];

void dfs_recursive(int x) {
	visited[x] = true;
	cout << x << " ";

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (visited[y] == false) {
			// 방문 
			dfs_recursive(y);
		}
	}
}

void dfs_stack(int start) {
	stack<int> stk;
	stk.push(start);  // stack에 push되면 탐색 되었음을 의미
	visited[start] = true; 
	cout << start << " ";

	while(!stk.empty()) {
		int cur = stk.top();
		stk.pop();
		
		for (int i = 0; i < graph[cur].size(); i++) {  // cur 노드에 인접한 노드
			// graph[cur][i] 에 인접한 노드들 탐색 
			int nxt = graph[cur][i];
			if (visited[nxt] == false) {
				visited[nxt] = true;
				cout << nxt << " ";
				stk.push(cur);  // 가장 최근 분기점
				stk.push(nxt);  // 다음 턴(while)에서 탐색할 노드
				break;
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


	dfs_recursive(1);

	for (int i = 0; i < 11; i++) {
		visited[i] = false;
	}
	cout << endl;
	dfs_stack(1);

	return 0;
}
