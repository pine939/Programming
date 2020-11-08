#include<stdio.h>
#define VERTEX_MAX 4
#define INF 987654321
int floyd_map[VERTEX_MAX][VERTEX_MAX] = {
    {0, 5, INF, 8},  // 1번정점
    {7, 0, 9, INF},  // 2번정점
    {2, INF, 0, 4},  // 3번정점
    {INF, INF, 3, 0}   // 4번정점
};

void floyd_warshall() {
    int d[VERTEX_MAX][VERTEX_MAX];
    
    // 결과 배열 초기화
    for (int i = 0; i < VERTEX_MAX; i++) {
        for (int j = 0; j < VERTEX_MAX; j++) {
            d[i][j] = floyd_map[i][j];
        }
    }

    // (출발지->중간지->도착지) < (출발지->도착지) 이면 최소값 갱신한다.
    for (int k = 0; k < VERTEX_MAX; k++) {
        for (int i = 0; i < VERTEX_MAX; i++) {
            for (int j = 0; j < VERTEX_MAX; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // i번째 정점에서 j번째 정점으로 가는 최소 비용 출력 
    for (int i = 0; i < VERTEX_MAX; i++) {
        printf("start number[%d] : ", i);
        for (int j = 0; j < VERTEX_MAX; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    floyd_warshall();   
}