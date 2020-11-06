#include<iostream>
#include<vector>
#include<algorithm>


// 잘못생각함... 이거 아니다 ㅠㅠ 
using namespace std;
int fence(const vector<int> &h, const vector<int> &h2) {
    vector<int> v_res;
    int last_idx = h.size() - 1;
    int res_h, res_w;
    for (int i = 0; i < h.size(); i++) {

        
        v_res.push_back((last_idx - i + 1) * h[i]);
    }
    res_h =  *max_element(v_res.begin(), v_res.end());

    res_w = 4;
    return res_h * res_w;
}

int main(void) {
    int C;
    int N;
    int height;
    vector<int> v_height;
    vector<int> v_height2;
    vector<int> result;
    cin >> C;
    if (C > 50 || C < 1) {
        return 0;
    }

    for (int i = 0; i < C; i++) {
        cin >> N;
        if (N > 20000 || N < 1) {
            return 0;
        }

        for(int j = 0; j < N; j++) {
            cin >> height;
            if (height > 10000 || height < 1) {
                return 0;
            }
            v_height.push_back(height);
            v_height2.push_back(height);
        }
        sort(v_height.begin(), v_height.end());
        result.push_back(fence(v_height, v_height));
    }
    
    for(int i = 0; i < C; i++) {
        cout << result[i] << endl;
    }
}