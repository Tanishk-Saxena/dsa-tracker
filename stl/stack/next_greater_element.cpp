#include<bits/stdc++.h>
using namespace std;

vector<int> findNGE(vector<int> &v) {
    stack<int> st;
    vector<int> nge(v.size(), -1);
    for (int i = 0; i < v.size(); i++) {
        while(!st.empty() && v[st.top()] < v[i]) {
            nge[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

void printVector(vector<int> v) {
    for (int e: v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        printVector(findNGE(v));
    }
    return 0;
}