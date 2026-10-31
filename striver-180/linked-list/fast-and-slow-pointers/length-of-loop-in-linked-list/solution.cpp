#include "../../../../utils/dsa_utils.hpp"
using namespace std;
using namespace dsa;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode *slow = head, *fast = head, *starting = nullptr;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                starting = slow;
                break;
            }
        }
        if (starting) {
            int count = 1;
            ListNode *iter = starting -> next;
            while(iter != starting) {
                count++;
                iter = iter -> next;
            }
            return count;
        }
        return 0;
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
    cout << sol.findLengthOfLoop(head) << endl;
    return 0;
}
