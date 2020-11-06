#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_vector(vector<pair<string, int> > &v) {
    vector<pair<string, int> >::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << "[" << it->first << ", " << it->second << "]  ";
    }
    cout << endl;
}

bool compare(pair<string, int> &p1, pair<string, int> &p2) {
    if (p1.first == p2.first) {  // 이름이 같다면
        return p1.second < p2.second;  // 나이가 적은 순서대로
    } else {  // 이름이 다르면
        return p1.first < p2.first;  // 사전 순서대로
    }
}

int main(void) {
    // array sort (오름차순, default)
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    sort(arr, arr+10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << "// array sort END " << endl << endl;

    // vector container sort (내림차순)
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << "// vector sort END" << endl << endl;

    // compare 나이를 기준으로 오름차순
    vector<pair<string, int> > v2;
    v2.push_back(pair<string, int> ("cc", 10));
    v2.push_back(pair<string, int> ("ba", 24));
    v2.push_back(pair<string ,int> ("aa", 11));
    v2.push_back(pair<string, int> ("cc", 8));
    v2.push_back(pair<string, int> ("bb", 21));

    print_vector(v2);
    sort(v2.begin(), v2.end(), compare);
    print_vector(v2);
    cout << "// compare sort END" << endl << endl;
}