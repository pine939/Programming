#include<iostream>
#include<vector>

using namespace std;

int number[3][5] = {
	{1,2,3,4,5},
	{10,20,30,40,50},
	{100,200,300,400,500},
};
int main() {

	vector <int> v;
	v.push_back(1);
	v.push_back(2);
	v.pop_back();

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
