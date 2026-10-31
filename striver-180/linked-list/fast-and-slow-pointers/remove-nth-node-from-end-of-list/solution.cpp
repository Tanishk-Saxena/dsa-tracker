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
    int recursiveRemoval (ListNode* head, int pos) {
        int count;
        if (head -> next) {
            count = recursiveRemoval(head -> next, pos);
        } else {
            count = 0;
        }
        if (count == pos) {
            head -> next = head -> next -> next;
        }
        return count + 1;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = recursiveRemoval(head, n);
        if (count == n) {
            head = head -> next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    int size, n;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    cin >> n;
    ListNode *res = sol.removeNthFromEnd(head, n);
    printList(res);
    return 0;
}
