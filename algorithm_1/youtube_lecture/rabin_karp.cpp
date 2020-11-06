/*
<라빈 카프 알고리즘>
- 항상 빠르지는 않지만 일반적인 경우 빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘
- 해시기법 사용
- 라빈 카프 알고리즘은 여러 개의 문자열을 비교할 때 먼저 해시값을 구하여 비교하고, 긴 글과 부분 문자열의 해시 값이 일치하는 경우에만 문자열을 재검사하여 정확히 일치하는지 확인하는 알고리즘이다. 

- 라빈 카프 알고리즘은 문자열의 해시 값을 비교하여 그 일치 여부를 검사하는 알고리즘이다. 
- 시간 복잡도는 O(N)이다. 문자열의 길이만큼 해시값을 비교하기 때문이다.
- 매우 빠른 이유는?  해시를 구하는 방법이 수학적으로 반복된다.
한 칸 뒤로 가면 맨 앞의 수를 빼고, 맨 뒤의 추가되는 것을 더하면 된다.(매우 간단...)
 */

#include <iostream>

using namespace std;

void find_string(string parent, string pattern) {
	int parent_size = parent.size();
	int pattern_size = pattern.size();
	int parent_hash = 0, pattern_hash = 0, power = 1;
	for (int i = 0; i <= (parent_size - pattern_size); i++) {
		if (i == 0) {
			for(int j = 0; j < pattern_size; j++) {
				parent_hash += parent[parent_size - 1 - j] * power;
				pattern_hash += pattern[pattern_size - 1 - j] * power;
				if (j < (pattern_size - 1)) power * 2;
			}
		} else {
			parent_hash = 2 * (parent_hash - parent[i-1] * power) + parent[pattern -1 + i];
		}
		if (parent_hash == pattern_hash) {
			bool finded = true;
			for (int j = 0; j < pattern_size; j ++) {
				if (parent[i + j] != pattern[j]) {
					finded = true;
				}
			}
			if (finded) printf("%d 번째에서 발견했습니다\n", i+1);
		}
	}
}

int main(void) {
	string parent = "dddd";
	string pattern = "dd";
	find_string(parent, pattern);
	return 0;
}
