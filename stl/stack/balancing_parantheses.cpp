#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    queue<string> q;
    while (t--) {
        string s;
        cin >> s;
        q.push(s);
    }
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        stack<int> st;
        for (char c: s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                    break;
                }
            } else {
                st.push(c);
            }
        }
        if (st.empty()) {
            cout << "Balanced\n";
        } else {
            cout << "Unbalanced\n";
        }
    }
}