
#pragma once

#include <bits/stdc++.h>

namespace dsa {

// ==================== Linked List Utilities ====================

struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int value, ListNode* nextNode = nullptr)
        : val(value), next(nextNode) {}
};

// Input space-separated integers, terminated by -1.
inline ListNode* inputList(int sentinel = -1) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int value;

    while (std::cin >> value && value != sentinel) {
        ListNode* node = new ListNode(value);

        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
    }

    return head;
}

// Create a linked list from a vector.
inline ListNode* makeList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        ListNode* node = new ListNode(value);

        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
    }

    return head;
}

// Print: 1 -> 2 -> 3 -> NULL
inline void printList(const ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }

    std::cout << "NULL\n";
}

// Free linked-list memory and set head to nullptr.
inline void deleteList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==================== Vector Utilities ====================

// Input n integers.
inline std::vector<int> inputVector(int n) {
    std::vector<int> values;

    if (n <= 0) {
        return values;
    }

    values.reserve(static_cast<std::size_t>(n));

    for (int i = 0; i < n; ++i) {
        int value;

        if (!(std::cin >> value)) {
            break;
        }

        values.push_back(value);
    }

    return values;
}

// Print: [1, 2, 3]
inline void printVector(const std::vector<int>& values) {
    std::cout << '[';

    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }

        std::cout << values[i];
    }

    std::cout << "]\n";
}

} // namespace dsa