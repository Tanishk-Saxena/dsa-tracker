#pragma once

#include <bits/stdc++.h>

namespace dsa {

// ==================== Vector Utilities ====================

// Read n values from stdin into a vector.
template <typename T = int>
std::vector<T> inputVector(int n) {
    std::vector<T> values;
    if (n <= 0) return values;

    values.reserve(static_cast<std::size_t>(n));
    T value;
    for (int i = 0; i < n && (std::cin >> value); ++i) {
        values.push_back(value);
    }
    return values;
}

// Read one LeetCode-style line like [1, 2, 3] into a vector (don't mix with `cin >> n` without cin.ignore()).
template <typename T = int>
std::vector<T> readVec() {
    std::string line;
    std::getline(std::cin, line);
    for (char& c : line) {
        if (c == '[' || c == ']' || c == ',') c = ' ';
    }

    std::istringstream ss(line);
    std::vector<T> values;
    T value;
    while (ss >> value) values.push_back(value);
    return values;
}

// Print a vector as [1, 2, 3].
template <typename T>
void printVector(const std::vector<T>& values, std::ostream& os = std::cout) {
    os << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) os << ", ";
        os << values[i];
    }
    os << "]\n";
}

// Print a 2D vector as [[1, 2], [3, 4]].
template <typename T>
void printMatrix(const std::vector<std::vector<T>>& grid, std::ostream& os = std::cout) {
    os << '[';
    for (std::size_t r = 0; r < grid.size(); ++r) {
        if (r > 0) os << ", ";
        os << '[';
        for (std::size_t c = 0; c < grid[r].size(); ++c) {
            if (c > 0) os << ", ";
            os << grid[r][c];
        }
        os << ']';
    }
    os << "]\n";
}

// ==================== Linked List Utilities ====================
// Uses the problem's own node type; needs a one-value constructor and members `val` and `next`.

// Type of the node's `val` member.
template <typename Node>
using ValueOf = std::remove_cv_t<decltype(Node::val)>;

// Build a list from a vector: makeList<ListNode>(v).
template <typename Node, typename T>
Node* makeList(const std::vector<T>& values) {
    Node dummy(T{});
    Node* tail = &dummy;
    for (const T& value : values) {
        tail->next = new Node(value);
        tail = tail->next;
    }
    return dummy.next;
}

// Read values from stdin until the sentinel (excluded from the list).
template <typename Node>
Node* inputList(ValueOf<Node> sentinel = ValueOf<Node>(-1)) {
    Node dummy(ValueOf<Node>{});
    Node* tail = &dummy;
    ValueOf<Node> value;
    while (std::cin >> value && value != sentinel) {
        tail->next = new Node(value);
        tail = tail->next;
    }
    return dummy.next;
}

// Read exactly `size` values from stdin into a list.
template <typename Node>
Node* inputListOfFixedSize(int size) {
    Node dummy(ValueOf<Node>{});
    Node* tail = &dummy;
    ValueOf<Node> value;
    for (int i = 0; i < size && (std::cin >> value); ++i) {
        tail->next = new Node(value);
        tail = tail->next;
    }
    return dummy.next;
}

// Copy a list's values into a vector.
template <typename Node>
std::vector<ValueOf<Node>> toVector(const Node* head) {
    std::vector<ValueOf<Node>> values;
    for (; head != nullptr; head = head->next) values.push_back(head->val);
    return values;
}

// Print a list as 1 -> 2 -> 3 -> NULL (infinite loop on a cyclic list).
template <typename Node>
void printList(const Node* head, std::ostream& os = std::cout) {
    for (; head != nullptr; head = head->next) os << head->val << " -> ";
    os << "NULL\n";
}

// Free every node and set head to nullptr.
template <typename Node>
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

} // namespace dsa