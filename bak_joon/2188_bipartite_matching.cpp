#include<iostream>
#include<vector>
#define MAX 201

bool c[MAX];
int n, m, s;

using namespace std;
bool dfs(int x) {
	// 연결된 모든 노드에 대해서 들어갈 수 있는지 시도합니다.
	for(int i = 0; i < a[i].size(); i++) {
		int t = a[i][x];
		// 이미 처리한 노드는 더 이상 볼 필요가 없음
		if(c[t]) continue;
		c[t] = true;
		// 비어 있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	scanf("%d %d", &n, &m); //소와 축사의 갯수
	for(int i = 1; i <= n; i++) {
		scanf("%d", &s); // 각각의 소가 몇개의 축사를 원하는지
		for(int j = 1; j <= s; j++) {
			int t;
			scanf("%d" &t);
			a[i].push_back(t);
		}
	}
	int count = 0; //최대 몇 개 까지 매칭이 이루어질 수 있는가
	for(int i = 1; i <= n; i++) {
		//최대한 우겨 넣습니다.
		fill(c, c+MAX, false);
		if(dfs(i)) count++;
	}
	printf("%d ", count);
	return 0;
}
