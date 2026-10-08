#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = INT_MIN;
        for (int num: nums) {
            if (count == 0) {
                el = num;
                count = 1;
            } else {
                if (num == el) {
                    count++;
                } else {
                    count --;
                }
            }
        }
        return el;
    }
};

int main() {
    Solution sol;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << sol.majorityElement(nums) << endl;
    }
    return 0;
}
