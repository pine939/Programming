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

int clock_sync() {
	int fin = 1;
	vector <int> need_to_mv_clk;

	for (int i = 0; i < 16; i++) {
		if (clock_state[i] != 12) {
			need_to_mv_clk.push_back(i);  // index
			fin = 0;
		}
	}

	if (fin == 1) {
		cout << "FIN " << endl;
		return cnt;
	}

	// 누를 스위치 결정
	int sw_mapping_cnt;
	int sw_max = 0;
	int sw_mapping_max_idx;
	for (int i = 0; i < 10; i++) {
		sw_mapping_cnt = 0;
		for (int j = 0; j < need_to_mv_clk.size(); j++) {
			int sw_idx = need_to_mv_clk[j];
			if ((1 & swich[i][sw_idx]) == 1) {
				sw_mapping_cnt++;
			}
		}
		if (sw_max <= sw_mapping_cnt) {
			sw_max = sw_mapping_cnt;
			sw_mapping_max_idx = i;
		}
	}

	cout << "SWITCH NUM : " << sw_mapping_max_idx << endl;
	// sw_mapping_max_idx 번째 스위치를 누른다.	
	sw_push(sw_mapping_max_idx);
	cnt++;

	if (need_to_mv_clk.size() != 0) {
		// cout << "swich number " << sw_mapping_max_idx << ", SIZE :" << need_to_mv_clk.size() << endl;
		//clock_sync();
	}

	for (int i = 0; i < 16; i++) {
		cout << clock_state[i] << " "; 
	}
	cout << '\n';

	return cnt;

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
		//cnt_arr[i] = clock_sync();
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
