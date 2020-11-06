#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(void) {
	int C;
	string member, fan;
	cin >> C;
	/*
	if (C > 20 || C < 1) {
		return 0;
	}

	for (int i = 0; i < C; i++) {
		cin >> member;  // FFFMMM
		cin >> fan;  // MMMFFF
		if (member > 2000000 || fan > 2000000 || member > fan) {
			return 0;
		}
	}
	*/
	int c[5];
	int a[5] = {0, 0, 0, 1, 1};
	int b[5] = {1, 0, 1, 1, 0};
	for (int i = 0; i < 5; i ++) {
		c[i] = a[i] & b[i];
		printf("%d ", c[i]);
	}

}

/*
   


 */
