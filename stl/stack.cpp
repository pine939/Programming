#include<iostream>
#include<stack>

using namespace std;
int main(void) {
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.pop();
    st.push(3);
    st.push(10);
    st.pop();
    st.push(11);

    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    // empty() : 스택이 비어 있으면 TRUE, 아니면 FALSE를 반환
    // size() : 스택 사이즈를 반환


    return 0;
}