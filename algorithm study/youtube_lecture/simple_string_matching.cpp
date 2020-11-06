#include<iostream>

using namespace std;

int find_string(string parent, string pattern) {
	 int parent_size = parent.size();
	 int pattern_size = pattern.size();
	 for (int i = 0; i < (parent_size - pattern_size); i++) {
		 bool finded = true;
		 for (int j = 0; j < pattern_size; j++) {
			 if (parent[i + j] != pattern[j]) {
				 finded = false;
				 break;
			 }
		 }
		 if (finded) return i;
	 }
	 return -1; // 실패
}

int main(void) {
	string parent = "hello world";
	string pattern = "hello";
	int result = find_string(parent, pattern);
	if (result == -1) {
		printf("찾을 수 없습니다\n");
	} else {
		printf("%d번 째에서 찾았습니다\n", result + 1);
	}
	return 0;
}
