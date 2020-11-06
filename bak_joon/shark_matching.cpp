#include<iostream>
#include<vector>

using namespace std;
bool dfs(int x) {
	for (int i = 1; i <= a[x].size(); i++) {
		int y = a[x][i];
		if(c[y]) continue;
		c[y] = true;

		if(d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		int a,b,c;
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	// 상어들 연결...
}
