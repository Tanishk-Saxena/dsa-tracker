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
    ListNode* reverseList(ListNode* head) {
        // recursive solution:
        // if (!head) { return nullptr; }
        // ListNode *tail = head;
        // if (head -> next) {
        //     tail = reverseList(head -> next);
        //     ListNode *temp = head -> next;
        //     head -> next = nullptr;
        //     temp -> next = head;
        // }
        // return tail;

        // iterative solution:
        ListNode *prev = nullptr, *curr = head;
        while(curr) {
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    Solution sol;
    int size;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    ListNode *tail = sol.reverseList(head);
    printList(tail);
    return 0;
}
