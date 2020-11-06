#include<iostream>
#include<cstring>

using namespace std;
int board_map[20][20];  // 1이면 black, 0이면 white
int type[4][2][2] = {
	{{1, 0}, {0, 1}},
	{{0, 1}, {1, 1}}, 
	{{1, 0}, {1, 1}},
	{{1, 0}, {1, -1}}
};
int H, W;


int find_type(int x, int y, int t, int wb) {  // x, y자리에 t모양을 놓을 수 있으면 return 1
	int new_x;
	int new_y;

	int ret = 1;
	if ((board_map[x][y] += wb) > 1) {
		ret = 0;
	}
	
	for (int i = 0; i < 2; i++) {
		new_x = x + type[t][i][0];
		new_y = y + type[t][i][1];

		// 범위가 벗어난 경우 
		if (new_x < 0 || new_y < 0 || new_x >= H || new_y >= W) {
			ret = 0;
		} else if ((board_map[new_x][new_y] += wb) > 1) {  // black block
			ret = 0;
		}
	}

	return ret;
}

int board_cover() { // white block이 보드를 덮는 경우의 수를 반환한다.
	int cnt; // 경우의 수
	int x = -1, y = -1;

    for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++){
			if (board_map[i][j] == 0) { // 남은 white블록이 있는 경우
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break; // 차례대로 
	}

	// 기저 사례
	if (x == -1) {  // 보드를 모두 덮은 경우
		return 1;
	}

	cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (find_type(x, y, i, 1)) {  // i타입으로 덮을 수 있으면  
			cnt += board_cover();  // 나머지 map도 채운다
		}
		// off
		find_type(x, y, i, -1);
	}
	return cnt;
}

int main(void) {
	int C;
	int cnt[30] = {0, };
	char block[20];
	int white_block_cnt;

	cin >> C;
	if (C > 50 || C < 1) return 0;
	for (int i = 0; i < C; i++) {
		memset(board_map, 0, sizeof(board_map));
		white_block_cnt = 0;
		cin >> H >> W; 
		if (H < 1 || W < 1 || W > 20) return 0;
		// H x W  행렬
		for (int j = 0; j < H; j++) {
			cin >> block;  // '#' or '.'
			for (int k = 0; k < W; k++) {
				if (block[k] == '#') {  // black block
					board_map[j][k] = 1;
				} else {
					white_block_cnt++;
				}
			}
		}
		if ((white_block_cnt % 3) == 0) { // white block이 3의 배수인 경우만 count
			cnt[i] = board_cover();
		} else {
			cnt[i] = 0;
		}
	}

	for (int i = 0; i < C; i++) {
		cout << cnt[i] << endl;
	}
}
