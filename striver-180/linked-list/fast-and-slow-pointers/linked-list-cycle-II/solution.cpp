#include "../../../../utils/dsa_utils.hpp"
using namespace std;
using namespace dsa;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    int size, pos;
    cin >> size;
    ListNode *head = inputListOfFixedSize<ListNode>(size);
    cin >> pos;
    if (pos != -1) {
        int i = 0;
        ListNode *iter = head, *intersection = nullptr, *end = nullptr;
        while (iter != nullptr) {
            if (i == pos) {
                intersection = iter;
            }
            if (iter -> next == nullptr) {
                end = iter;
            }
            iter = iter -> next;
            i++;
        }
        end -> next = intersection;
    }
    ListNode *cycleStart = sol.detectCycle(head);
    if (cycleStart == nullptr) {
        cout << "no cycle" << endl;
    } else {
        ListNode *iter = head;
        int index = 0;
        while(iter != cycleStart) {
            index++;
            iter = iter -> next;
        }
        cout << "tail connects to node at index " << index << endl;
    }
    return 0;
}
