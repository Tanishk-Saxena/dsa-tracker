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
    ListNode* reverseLL(ListNode* head) {
        ListNode* next = head -> next;
        ListNode* tail;
        if (next -> next) {
            tail = reverseLL(next);
        } else {
            tail = next;
        }
        next -> next = head;
        return tail;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!(head) || !(head -> next)) {
            return head ? true : false;
        }
        ListNode *slow = head -> next, *fast = head -> next -> next;
        while(fast && (fast -> next)) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if (fast) {
            slow = slow -> next;
        }
        ListNode* reversedSecondHalfHead;
        if (slow -> next) {
            reversedSecondHalfHead = reverseLL(slow);
        } else {
            reversedSecondHalfHead = slow;
        }
        slow -> next = nullptr;
        ListNode* iter1 = head;
        ListNode* iter2 = reversedSecondHalfHead;
        while(iter1 && iter2) {
            if ((iter1 -> val) != (iter2 -> val)) {
                return false;
            }
            iter1 = iter1 -> next;
            iter2 = iter2 -> next;
        }
        if (reversedSecondHalfHead != slow) {
            ListNode* originalSecondHalfHead = reverseLL(reversedSecondHalfHead);
            reversedSecondHalfHead -> next = nullptr;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int size;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    cout << (sol.isPalindrome(head) ? "true" : "false") << endl;
    return 0;
}
