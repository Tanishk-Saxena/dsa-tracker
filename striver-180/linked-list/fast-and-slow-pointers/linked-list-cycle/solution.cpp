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
    bool hasCycle(ListNode *head) {
        if (!head || !(head -> next)) return false;
        ListNode *slow = head -> next, *fast = head -> next -> next;
        while(slow && fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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
    cout << (sol.hasCycle(head) ? "true" : "false") << endl;
    return 0;
}
