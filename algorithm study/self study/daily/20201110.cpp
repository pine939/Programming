/*
1. STL // priority queue
2. BFS/DFS
3. BINARY SEARCH  //
4. BINARY TREE
5. DP
6. DIJKSTRA
7. FLOYD_WARSHALL
*/

#include<iostream>
#include<queue>
#include<stack>
#include<list>

using namespace std;
vector<int> m[6];
int b_visited[6];
int d_visited[6];
void bfs(int x) {
    queue<int> q;
    q.push(x);
    
    while(!q.empty()) {
        int data = q.front();
        q.pop();
        b_visited[data] = 1;
        cout << data << " ";

        for (int i = 0; i < m[data].size(); i++) {
            int a = m[data][i];
            if (b_visited[a] != 1) {
                q.push(a);
            }
        }
    }
    cout << endl;
}

void dfs(int x) {
    stack<int> s;
    s.push(x);

    while(!s.empty()) {
        int data = s.top();
        s.pop();
        d_visited[data] = 1;
        cout << data << " ";

        for (int i = 0; i < m[data].size(); i++) {
            int a = m[data][i];
            if (d_visited[a] != 1) {
                s.push(a);
            }
        }
    }
    cout << endl;
}

vector<int> l;
void binary_search(int x, int s, int e) {
    int mid;
    while(s <= e) {
        mid = (s + e) / 2;
        if (l[mid] == x) {
            cout << "Find!" << endl;
            return;
        } else if (l[mid] > x) {
            e = mid - 1;
        } else if (l[mid] < x) {
            s = mid + 1;
        }
    }
    cout << "Not Exist!" << endl;
}

int main(void) {
    // STL : priority_queue, queue, list
    /*
    1. priority queue : push, top, pop, size, empty
    */
    priority_queue<int> pq;  // 최대 힙 (큰 수가 가중치가 크다!)
    cout << "[[priority queue]] SIZE :" << pq.size() << endl;
    cout << "PUSH" << endl;
    pq.push(1);
    pq.push(2);
    pq.push(10);
    pq.push(8);
    pq.push(5);
    pq.push(8);
    cout << "SIZE :" << pq.size() << endl;
    cout << "PQ status(0: not empty, 1:empty) :" << pq.empty() << endl;

    int top = pq.top();
    cout << "TOP :" << top << endl;  // 10
    cout << "POP!" << endl;
    pq.pop();
    cout << "SIZE :" << pq.size() << endl << endl;

    priority_queue<int, vector<int>, greater<int> > pq2;  // 최소 힙
    cout << "[[priority queue2]] SIZE :" << pq2.size() << endl;
    pq2.push(1);
    pq2.push(2);
    pq2.push(10);
    pq2.push(8);
    pq2.push(5);
    pq2.push(8);
    cout << "SIZE : " << pq2.size() << endl;
    cout << "PQ status(0: not empty, 1: empty) :" << pq2.empty() << endl;

    cout << "TOP : " << pq2.top() << endl;  // 1
    cout << "POP!" <<endl;
    pq2.pop();
    cout << "SIZE : " << pq2.size() << endl;

    cout << "----------------------------" << endl;

    // BFS/DFS
    /*
    2. BFS : 너비우선탐색, queue
    3. DFS : 깊이우선탐색, stack
    */
   m[1].push_back(2);
   m[2].push_back(1);
   
   m[1].push_back(3);
   m[3].push_back(1);

   m[2].push_back(4);
   m[4].push_back(2);

   m[2].push_back(5);
   m[5].push_back(2);

   cout << "BFS" << endl;
   bfs(1);
   cout << "DFS" << endl;
   dfs(1);
   cout << "----------------------------" << endl;

    // BINARY SEARCH
    cout << "[[binary search]] " << endl << "List : ";
    l.push_back(1);
    l.push_back(3);
    l.push_back(4);
    l.push_back(7);
    l.push_back(10);
    l.push_back(11);
    l.push_back(14);
    l.push_back(15);
    l.push_back(19);
    l.push_back(22);

    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
    }

    cout << endl;
    cout << "Search number : 4" << endl;
    binary_search(4, 0, 9); 
    cout << "Search number : 15" << endl;
    binary_search(15, 0, 9);
    cout << "Search number : 12" << endl;
    binary_search(12, 0, 9);
}