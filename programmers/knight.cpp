#include<iostream>
#include<cstring>

using namespace std;

int dx[8] = {-2,-2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
/*
ascii 
a = 97
...
h = 104

1 = 49
...
8 = 56
*/

int solution(string str) {
    // c2 
    // str[0] : dx[0] ~ dx[7] 97 미만이거나 104 초과이면 continue
    // str[1] : dy[0] ~ dy[7] 1 미만이거나 8초과이면 continue
    int tmp_x, tmp_y;
    int result = 0;
    for (int i = 0; i < 8; i++) {
        tmp_x = str[0] + dx[i];
        tmp_y = str[1] + dy[i];

        if (tmp_x < 97 || tmp_x > 104 || tmp_y < 49 || tmp_y > 56) {
            continue;
        }
        result++;
        /*
        (-2, -1), (-2, 1), (2, -1), (2, 1) (-1, -2), ... 8개 좌표
        */
    }
    return result;

}

int main(void) {
    string str;
    int result;
    cin >> str;
    result = solution(str);
    cout << result << endl;
}