#include "../../../../utils/dsa_utils.hpp";
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
    ListNode* middleNode(ListNode* head) {
        ListNode* working_head = head;
        int n = 0;
        while(working_head) {
            n++;
            working_head = working_head -> next;
        }
        int mid = n/2;
        n = 1;
        working_head = head;
        while (n <= mid) {
            n++;
            working_head = working_head -> next;
        }
        return working_head;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    ListNode *head = inputListOfFixedSize<ListNode>(n);
    ListNode *middle = sol.middleNode(head);
    printList(middle);
    return 0;
}
