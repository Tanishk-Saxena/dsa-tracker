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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int length = 0;
        ListNode *iter = head, *end = nullptr;
        while (iter) {
            length++;
            if (iter -> next == nullptr) {
                end = iter;
            }
            iter = iter -> next;
        }
        int rotation = k % length;
        if (!rotation) {
            return head;
        }
        int cutoff_len = length - rotation;
        int count = 1;
        iter = head;
        while (count < cutoff_len) {
            count++;
            iter = iter -> next;
        }
        ListNode *next = iter -> next;
        iter -> next = nullptr;
        end -> next = head;
        return next;
    }
};

int main() {
    Solution sol;
    int size, k;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    cin >> k;
    ListNode *res = sol.rotateRight(head, k);
    printList(res);
    return 0;
}
