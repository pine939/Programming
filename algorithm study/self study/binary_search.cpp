#include<iostream>
#include<vector>
#include<algorithm>
/*
v_size만큼의 vector에서 data를 binary search
*/
using namespace std;

vector<int> v;
int binary_search(int data, int v_min, int v_max) {
    while (v_min <= v_max) {
        int v_mid = (v_max + v_min) / 2;
        if (data == v[v_mid]) {
            return v_mid;
        } else if (data < v[v_mid]) {
            v_max = v_mid - 1;
        } else {
            v_min = v_mid + 1;
        }
    }
    return -1;  // not found
}

int main(void){
    int v_size, v_data, data;
    cout << "Enter v_size : ";
    cin >> v_size;

    cout << "Enter vector :";
    for (int i = 0; i < v_size; i++) {
        cin >> v_data;
        v.push_back(v_data);
    }

    cout << "Sort vector : ";
    sort(v.begin(), v.end());
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Enter data :";
    cin >> data;

    int ret = binary_search(data, 0, v.size()-1);
    if (ret < 0) {
        cout << "Not Found" << endl;
    } else {
        cout << "Find! (index = " << ret << ")" << endl;
    }
}
