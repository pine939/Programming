#include<stdio.h>

int number = 4;
int INF = 100000000; // 백만

// 자료 배열을 초기화 합니다.
int a[4][4] = {
	{0, 5, 100, 8},
	{7, 0, 9, 100},
	{2, 100, 0, 4},
	{100, 100, 3, 0}
};

void floyd_warshall() {
	// 결과 그래프를 초기화 합니다.
	int d[number][number];
	for (int i=0; i < number; i++) {
		for (int j=0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드 
	for (int k = 0; k < number; k ++) {
		// i = 출발 노드
		for (int i = 0; i < number; i++) {
			// j = 도착 노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과를 출력합니다.
	for (int i = 0; i < number; i++) {
		for(int j = 0; j < number; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

}


void main() {
	floyd_warshall();
}
