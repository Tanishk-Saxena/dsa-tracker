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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA && ptrB) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA -> next;
            ptrB = ptrB -> next;
        }
        if (ptrA == nullptr && ptrB) {
            ptrA = headB;
            while(ptrB) {
                ptrA = ptrA -> next;
                ptrB = ptrB -> next;
            }
            ptrB = headA;
        } else if (ptrB == nullptr && ptrA) {
            ptrB = headA;
            while(ptrA) {
                ptrA = ptrA -> next;
                ptrB = ptrB -> next;
            }
            ptrA = headB;
        }
        while(ptrA && ptrB) {
            if (ptrA == ptrB) {
                return ptrA;
            }
            ptrA = ptrA -> next;
            ptrB = ptrB -> next;
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    int intersectVal, sizeListA, sizeListB, skipA, skipB;
    ListNode *headListA = nullptr, *headListB = nullptr;
    cin >> intersectVal;
    cin >> sizeListA;
    headListA = inputListOfFixedSize<ListNode>(sizeListA);
    cin >> sizeListB;
    if (intersectVal != 0) {
        vector<int> temp_v = inputVector(sizeListB);
        cin >> skipA >> skipB;
        headListB = makeList<ListNode>(vector<int>(temp_v.begin(), temp_v.begin() + skipB));
        int countA = 0, countB = 0;
        ListNode *iterA = headListA, *iterB = headListB;
        while(countA != skipA) {
            iterA = iterA -> next;
            countA++;
        }
        while(countB != skipB-1) {
            iterB = iterB -> next;
            countB++;
        }
        iterB -> next = iterA;
    } else {
        headListB = inputListOfFixedSize<ListNode>(sizeListB);
        cin >> skipA >> skipB;
    }
    ListNode *res = sol.getIntersectionNode(headListA, headListB);
    if (res != nullptr) {
        cout << "Intersected at " << res -> val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    return 0;
}