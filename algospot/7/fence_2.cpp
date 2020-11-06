#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;

int fence(const vector<int> &h) {
    vector <int> v_fence;
    int cur_h; 
    for (int i = 0; i < h.size(); i++) {
        cur_h = h[i];
        int cur_w_r = 0, cur_w_l = 0, cur_w = 0;
        if (i == 0) {
            for (int j = 0; j < h.size(); j++) {
                if (h[i] <= h[j]) {
                    cur_w_r++;
                } else {
                    break;
                }
            }
            cur_w = cur_w_r;
            v_fence.push_back(cur_h*cur_w);
            continue;
        }           

        // IDX (i-1) ~ 0
        for (int j = (i-1); j >= 0; j--) {
            if (h[i] <= h[j]) {
                cur_w_l++;
            } else {
                break;
            }
        }

        // IDX i ~ (h.size()-1)
        for (int j = i; j < h.size(); j++) {
            if (h[i] <= h[j]) {
                cur_w_r++;
            } else {
                break;
            }
        }
        cur_w = cur_w_l + cur_w_r;
        v_fence.push_back(cur_h*cur_w);
    }
    return *max_element(v_fence.begin(), v_fence.end());
}

int main(void) {
    int C;
    int N;
    int height;
    vector<int> result;
    vector<int> v_height;
    cin >> C;
    if (C > 50 || C < 1) {
        return 0;
    }

    for (int i = 0; i < C; i++) {
        v_height.clear();
        cin >> N;
        if (N > 20000 || N < 1) {
            return 0;
        }

        for(int j = 0; j < N; j++) {
            cin >> height;
            if (height > 10000 || height < 0) {
                return 0;
            }
            v_height.push_back(height);
        }
        result.push_back(fence(v_height));
    }
    
    for(int i = 0; i < C; i++) {
        cout << result[i] << endl;
    }
}
