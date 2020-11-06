#include<iostream>
#include<string>
#include<cstring>

using namespace std;
char boggle[5][5] = {0, };
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int check[5][5][10];

int has_word(int x, int y, const string &word, int idx) {
	int next_x, next_y;
	int res = 0;
	// 기저 제외
	if (x < 0 || y < 0 || x >=5 || y >= 5) {
		return 0;
	}

	if (word.size() == 1) {
		return (word[0] == boggle[x][y]);
	}

	if (word[0] != boggle[x][y]) {
		return 0;
	}

	if (check[x][y][idx] == 1) {
		return 0;
	}
	check[x][y][idx] = 1;

	for (int i = 0; i < 8; i++) {
		next_x = x + dx[i];
		next_y = y + dy[i];
		res =  has_word(next_x, next_y, word.substr(1), idx + 1);
		if (res == 1) return res;
	}
	return res;
}

int main(void) {
	int test_case;
	int N;
	string word[10];
	int idx = 0;
	int res;
	cin >> test_case;

	if (test_case > 50 || test_case < 0) return 0;
	for (int i = 0; i < test_case; i++) {
		// boggle 입력
		for (int j = 0; j < 5; j++) {
			for(int k = 0; k < 5; k++) {
				cin >> boggle[j][k];
			}
		}

		// 단어 입력
		cin >> N;
		if (N < 1 || N > 10) return 0;
		for (int j = 0; j < N; j++) {
			cin >> word[j];
		}

		// has_word
		for (int k = 0; k < N; k++) {
			memset(check, 0, sizeof(check));
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 5; y++) {
					res = has_word(x, y, word[k], idx);
					if (res) break;
				}
				if (res) break;
			}
			// 출력
			if (res) {
				cout << word[k] << " YES" << endl;
			} else {
				cout << word[k] << " NO" << endl;
			}
		}
	}

	return 0;
}
