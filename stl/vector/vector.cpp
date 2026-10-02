#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 0; i < 20; i++) {
        v.push_back(i);
    }

    cout << "The elements in the vector are: ";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    auto beginIterator = v.begin();
    auto endIterator = v.end();

    v.insert(1, 5);


    return 0;
}