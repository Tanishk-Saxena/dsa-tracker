#include "../../../../utils/dsa_utils.hpp"
using namespace std;
using namespace dsa;

class ListNode{
  public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            //your code goes here
            ListNode *zero_head = nullptr, *zero_iter = nullptr, *one_head = nullptr, *one_iter = nullptr, *two_head = nullptr, *two_iter = nullptr, *iter = head;
            while(iter) {
                switch(iter -> val) {
                    case 0:
                        if (!zero_head) {
                            zero_head = iter;
                        } else {
                            zero_iter -> next = iter;
                        }
                        zero_iter = iter;
                        break;
                    case 1:
                        if (!one_head) {
                            one_head = iter;
                        } else {
                            one_iter -> next = iter;
                        }
                        one_iter = iter;
                        break;
                    case 2:
                        if (!two_head) {
                            two_head = iter;
                        } else {
                            two_iter -> next = iter;
                        }
                        two_iter = iter;
                        break;
                }
                iter = iter -> next;
            }
            if (zero_iter) {
                zero_iter -> next = one_head ? one_head : two_head;
            }
            if (one_iter) {
                one_iter -> next = two_head;
            }
            if (two_iter) {
                two_iter -> next = nullptr;
            }
            return zero_head ? zero_head : (one_head ? one_head : two_head);
        }
};

int main() {
    Solution sol;
    int size;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    ListNode *res = sol.sortList(head);
    printList(res);
    return 0;
}
