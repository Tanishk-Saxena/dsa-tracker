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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list = nullptr, *iter = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            ListNode *minNode;
            if (list1 -> val <= list2 -> val) {
                minNode = list1;
                list1 = list1 -> next;
            } else {
                minNode = list2;
                list2 = list2 -> next;
            }
            if (iter) {
                iter -> next = minNode;
                iter = iter -> next;
            } else {
                list = minNode;
                iter = list;
            }
        }
        if (list1 && !list2) {
            if (iter) {
                iter -> next = list1;
            } else {
                return list1;
            }
        } else if (list2 && !list1) {
            if (iter) {
                iter -> next = list2;
            } else {
                return list2;
            }
        }
        return list;
    }
};

int main() {
    Solution sol;
    int size1, size2;
    cin >> size1;
    ListNode *head1 = inputListOfFixedSize<ListNode>(size1);
    cin >> size2;
    ListNode *head2 = inputListOfFixedSize<ListNode>(size2);
    ListNode *res = sol.mergeTwoLists(head1, head2);
    printList(res);
    return 0;
}
