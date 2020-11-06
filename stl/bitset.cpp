#include<iostream>
#include<bitset>

using namespace std;

int main(void) {
    bitset<100000> a(76), b(44); // 각각 76, 44의 비트가 입력됨
    cout << (a & b) << '\n';

    return 0;
}