#include<stdio.h>
#include<string.h>

char tmp_result[1000];
int g_idx;
char *quad_tree(char *str) {
    char res_str_1[1000], res_str_2[1000], res_str_3[1000], res_str_4[1000];
    memset(tmp_result, 0, sizeof(tmp_result));

    // 첫 글자가 w, b인 경우 그대로 반환한다.
    if (str[g_idx] == 'w' || str[g_idx] == 'b') {
        snprintf(tmp_result, sizeof(tmp_result), "%c", str[g_idx]);
        return tmp_result;
    }

    
    // x인 경우 4분면으로 나누어 상하반전 한다.
    g_idx++;
    snprintf(res_str_1, sizeof(res_str_1), "%s", quad_tree(str));
    g_idx++;
    snprintf(res_str_2, sizeof(res_str_2), "%s", quad_tree(str));
    g_idx++;
    snprintf(res_str_3, sizeof(res_str_3), "%s", quad_tree(str));
    g_idx++;
    snprintf(res_str_4, sizeof(res_str_4), "%s", quad_tree(str));

    snprintf(tmp_result, sizeof(tmp_result), "x%s%s%s%s", res_str_3, res_str_4, res_str_1, res_str_2);
    return tmp_result;
}

int main(void) {
    int C;
    int i;
    char str[1000] = {0, };
    char result_str[50][1000] = {{0, }};

    // test case 입력
    scanf("%d", &C);
    if (C > 50 || C < 1) {
        return 0;
    }

    // quad tree 구하기
    for (i = 0; i < C; i++) {
        g_idx = 0;
        scanf("%s", str);
        snprintf(result_str[i], sizeof(result_str[i]), "%s", quad_tree(str));
    }

    // 결과 출력
    for (i = 0; i < C; i++) {
        printf("%s\n", result_str[i]);
    }    
    
}