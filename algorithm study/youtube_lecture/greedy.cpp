// 극단적으로 문제를 접근한다. (무조건 큰 경우대로, 작은 경우대로, ...)
// 정렬기법 함께 사용
// 크루스칼 알고리즘 
// 엄청 다양하고 많이 쓰인다. 

#include <iostream>

using namespace std;

int main(void) {
	int n, result = 0;
	cin >> n;
	result += n/500;
	n %= 500;
	result += n / 100;
	n %= 100;
	result += n / 50;
	n %= 50;
	result += n / 10;
	cout << result;
	return 0;
}
