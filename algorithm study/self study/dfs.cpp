#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int visited[10];
vector<int> dfs_map[10];

/*
깊이 우선 탐색 (스택)
1. 첫 노드 x를 스택에 넣는다.
2. x를 방문처리한다.
3. stack이 empty될 때 까지 
  3-1. 스택의 top을 pop한다. (data)
  3-2. data를 방문 처리한다.
  3-3. data와 연결된 노드을 방문하여 방문처리되지 않았다면 방문한다.
*/
void dfs(int x) {
    stack<int> s;
    s.push(x);

    while(!s.empty()) {
        int data = s.top();
        s.pop();
        visited[data] = 1;
        printf("%d ", data);
        for (int i = 0; i < dfs_map[data].size(); i++) {
            if (visited[dfs_map[data][i]] != 1) {
                s.push(dfs_map[data][i]);
                // printf("push data :%d\n", dfs_map[data][i]);
            }
        }
    }
}

int main(void) {
    dfs_map[1].push_back(2);
    dfs_map[2].push_back(1);

    dfs_map[1].push_back(3);
    dfs_map[3].push_back(1);

    dfs_map[2].push_back(4);
    dfs_map[4].push_back(2);

    dfs_map[2].push_back(8);
    dfs_map[8].push_back(2);

    dfs_map[8].push_back(9);
    dfs_map[9].push_back(8);

    dfs_map[3].push_back(5);
    dfs_map[5].push_back(3);

    dfs_map[3].push_back(6);
    dfs_map[6].push_back(3);

    dfs_map[6].push_back(7);
    dfs_map[7].push_back(6);

    dfs(1);
}