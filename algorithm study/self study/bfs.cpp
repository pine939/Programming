#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> bfs_map[10];
int visited[10];
void bfs(int x) {
   queue<int> q;
   q.push(x);

   while(!q.empty()) {
       int data = q.front();
       q.pop();
       visited[data] = 1;
       printf("%d ", data);
       for (int i = 0; i < bfs_map[data].size(); i++) {
           if (visited[bfs_map[data][i]] != 1) {
               q.push(bfs_map[data][i]);
           }
       }
   }
}

int main(void) {
    bfs_map[1].push_back(2);
    bfs_map[2].push_back(1);

    bfs_map[1].push_back(3);
    bfs_map[3].push_back(1);

    bfs_map[2].push_back(4);
    bfs_map[4].push_back(2);

    bfs_map[2].push_back(8);
    bfs_map[8].push_back(2);

    bfs_map[8].push_back(9);
    bfs_map[9].push_back(8);

    bfs_map[3].push_back(5);
    bfs_map[5].push_back(3);

    bfs_map[3].push_back(6);
    bfs_map[6].push_back(3);

    bfs_map[6].push_back(7);
    bfs_map[7].push_back(6);

    bfs(1);
}