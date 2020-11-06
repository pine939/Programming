#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

double festival(const vector<int> &v) {
    vector<double> means;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    
    
    return *min_element(means.begin(), means.end());
}

int main(void) {
    int C, N, L;
    int cost;
    //double test = 10.0/3.0;
    //printf("%.7f\n", test);
    //cout << fixed;
    //cout.precision(7);
    //cout << test << endl;
    vector<int> v_cost;
    cin >> C;
    if (C > 100 || C < 1) {
        return 0;
    }

    for (int i = 0; i < C; i++) {
        cin >> N >> L;
        if (N > 1000 || N < 1 || L > 1000 || L < 1 || L > N) {
            return 0;
        }

        for (int j = 0; j < N; j++) {
            cin >> cost;
            v_cost.push_back(cost);
            cout << festival(v_cost) << endl;
        }
    }
}