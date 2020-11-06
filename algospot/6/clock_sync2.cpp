#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int clock_state[16];
const int INF = 9999;
int swich[10][16] = {
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0 (0,1,2)
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},  // 1 (3,7,9,11)
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},  // 2 (4,10,14,15)
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // 3 (0,4,5,6,7)
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},  // 4 (6,7,8,10,12)
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},  // 5 (0,2,14,15)
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},  // 6 (3,14,15)
	{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},  // 7 (4,5,7,14,15)
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 8 (1,2,3,4,5)
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}   // 9 (3,4,5,9,13)
};

int cnt;
int is_synced() {
	int fin = 1;
	for (int i = 0; i < 16; i ++) {
		if (clock_state[i] != 12) {
			fin = 0;
			break;
		}
	}
	return fin;
}

void sw_push(int swich_num) {
	for (int i = 0; i < 16; i++) {
		if (swich[swich_num][i] == 1) {
			clock_state[i] += 3;
			if (clock_state[i] == 15) {
				clock_state[i] = 3;
			}
		}
	}
}

int clock_sync2(int swich_num) {
	if (swich_num == 10) {
		return is_synced() ? 0 : INF;  // 모든 시계가 12시면 0을 반환한다.
	}

	int ret = INF;

	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + clock_sync2(swich_num + 1));
		sw_push(swich_num);
	}

	return ret;
}

int main(void) {
	int C;
	int cnt_arr[30];
	cin >> C;
	if (C > 30 || C < 1) return 0;

	for (int i = 0; i < C; i++) {
		memset(clock_state, 0, sizeof(clock_state));
		cnt = 0;
		for (int j = 0; j < 16; j++) {
			cin >> clock_state[j];
		}
		cnt_arr[i] = clock_sync2(0);
	}

	for (int i = 0; i < C; i++) {
		if (cnt_arr[i] >= INF) {
			cout << -1 << endl;
		} else {
			cout << cnt_arr[i] << endl;
		}
	}
}
