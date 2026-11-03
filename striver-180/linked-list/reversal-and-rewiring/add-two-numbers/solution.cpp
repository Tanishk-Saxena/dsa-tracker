#include "../../../../utils/dsa_utils.hpp"
using namespace std;
using namespace dsa;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum_head = nullptr, *sum_iter = nullptr, *l1_iter = l1, *l2_iter = l2;
        int carry = 0;
        while (l1_iter && l2_iter) {
            int digit_sum = l1_iter -> val + l2_iter -> val + carry;
            ListNode* digit = new ListNode(digit_sum % 10);
            if (!sum_head) {
                sum_head = digit;
            } else {
                sum_iter -> next = digit;
            }
            sum_iter = digit;
            carry = digit_sum >= 10 ? 1 : 0;
            l1_iter = l1_iter -> next;
            l2_iter = l2_iter -> next;
        }
        while (l1_iter) {
            int digit_sum = l1_iter -> val + carry;
            carry = digit_sum >= 10 ? 1 : 0;
            ListNode* digit = new ListNode(digit_sum % 10);
            sum_iter -> next = digit;
            sum_iter = digit;
            l1_iter = l1_iter -> next;
        }
        while (l2_iter) {
            int digit_sum = l2_iter -> val + carry;
            carry = digit_sum >= 10 ? 1 : 0;
            ListNode* digit = new ListNode(digit_sum % 10);
            sum_iter -> next = digit;
            sum_iter = digit;
            l2_iter = l2_iter -> next;
        }
        if (carry) {
            ListNode* digit = new ListNode(1);
            sum_iter -> next = digit;
        }
        return sum_head;
    }
};

int main() {
    Solution sol;
    int size1, size2;
    cin >> size1;
    ListNode *num1 = inputListOfFixedSize<ListNode>(size1);
    cin >> size2;
    ListNode *num2 = inputListOfFixedSize<ListNode>(size2);
    ListNode *res = sol.addTwoNumbers(num1, num2);
    printList(res);
    return 0;
}
