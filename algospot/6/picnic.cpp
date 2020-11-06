#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int friend_flag[10][10];
int check[10];
int picnic(int n) {
	int fast = -1;

	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			fast = i;
			break;
		}
	}

	if (fast == -1) {
		return 1;
	}

	int cnt = 0;
	for (int i = fast+1; i < n; i++) {
		if ((check[i] == 0) && (friend_flag[fast][i] == 1)) {
			check[fast] = 1;
			check[i] = 1;
			cnt += picnic(n);
			check[fast] = 0;
			check[i] = 0;
		}
	}
	return cnt;
}

int main(void) {
	int C;
	int n, m;
	int a, b;
	int cnt[50];

	cin >> C;
	if (C > 50 || C < 1) return 0;

	for (int i = 0; i < C; i++) {
		cin >> n >> m;
		memset(friend_flag, 0, sizeof(friend_flag));
		memset(check, 0, sizeof(check));
		if (n < 2 || n > 10 || m < 0 || m > (n*(n-1)/2)) return 0;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			friend_flag[a][b] = 1;
			friend_flag[b][a] = 1;
		}
		cnt[i] = picnic(n);
	}

	for (int i = 0; i < C; i++) {
		cout << cnt[i] << endl;
	}
}
