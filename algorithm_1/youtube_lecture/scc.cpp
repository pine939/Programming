#include<iostream>
#include<vector>
#include<stack>
#define MAX 10001  // 가능한 총 노드 개수

using namespace std;

int id, d[MAX]; // 각 노드마다 고유 번호 할당
bool finished[MAX];  // 특정 노드에 대한 dfs끝났는지 확인
vector<int> a[MAX];  // 인접한 노드
vector<vector<int>> SCC;  // 2차원 벡터
stack<int> s;  

// dfs는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x) {
	d[x] = ++id; // 노드마다 고유한 번호 할당
	s.push(x);  // 스택에 자기 자신을 삽입합니다.

	int parent = d[x];  // 자신의 부모가 누구인가. (처음은 자신이 부모)

	for(int i = 0; i < a[x].size; i++) {
		int y = a[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y));  // 방문하지 않은 이
		else if(!finished[y]) parent = min(parent, d[y]); // 처리중인 이웃
	}
}
