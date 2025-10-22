

#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <sstream>
#include <tuple>
#include <utility>
using namespace std;

// Common LeetCode helpers

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helpers to build vectors/lists quickly in tests
inline vector<int> vec(initializer_list<int> il) { return vector<int>(il); }

inline ListNode* list_from_vec(const vector<int>& v) {
    ListNode dummy(0); auto* cur = &dummy;
    for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }
    return dummy.next;
}

inline vector<int> vec_from_list(ListNode* head) {
    vector<int> v; for (; head; head=head->next) v.push_back(head->val);
    return v;
}

// Basic BST insert (for quick trees in tests)
inline TreeNode* bst_insert(TreeNode* root, int x) {
    if (!root) return new TreeNode(x);
    if (x < root->val) root->left = bst_insert(root->left, x);
    else               root->right = bst_insert(root->right, x);
    return root;
}
