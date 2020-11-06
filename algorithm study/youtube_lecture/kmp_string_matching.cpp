#include <iostream>
#include <vector>

using namespace std;

vector<int> make_table(string pattern) {  // 접두사와 접미사를 포함하는 테이블 만들기
	int pattern_size = pattern.size();
	vector<int> table(pattern_size, 0);

	int j = 0;
	int i = 1;
	for (i = 1; i < pattern_size; i++) {
		while(j > 0 && (pattern[i] != pattern[j])) {
			j = table[j-1]; // 일치하지 않았을 때
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = make_table(pattern);
	int parent_size = parent.size();
	int pattern_size = pattern.size();
	int j = 0;
	for (i = 0; i < parent_size; i++) {
		while(j > 0 && (parent[i] != parent[j])) {  // 일치하지 않음
			j = table[j - 1]; // table[j - 1]까지는 일치한다.
		}
		if (parent[i] == parent[j]) {
			if(j == parent_size-1) {
				printf("%d번째에서 찾았습니다\n", (i - pattern_size + 2));
				j = table[j];  //jump
			} else {
				j++;
			}
		}
	}
}

int main(void) {
	string parent = "abacabacabacabaa";
	string pattern = "abacaaba";
	vector<int> table = make_table(pattern);
	for(int i = 0; i < table.size(); i++) {
		printf("%d ", table[i]);
	}

	return 0;
}
