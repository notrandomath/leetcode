/*
 * @lc app=leetcode id=3479 lang=cpp
 *
 * [3479] Fruits Into Baskets III
 */

#include<vector>
#include<list>
using namespace std;

// @lc code=start
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val):val{val},left{nullptr},right{nullptr},parent{nullptr}{}
    Node(Node* left, Node* right):val{max(left->val, right->val)},left{left},right{right},parent{nullptr}{
        left->parent = this;
        right->parent = this;
    }
    void erase_node() {
        if (parent && parent->left == this) parent->left = nullptr;
        if (parent && parent->right == this) parent->right = nullptr;
        while (parent) {
            parent->val = max(
                parent->left ? parent->left->val : -1,
                parent->right ? parent->right->val : -1
            );
            parent = parent->parent;
        }
    }
    Node* search(int val) {
        if (!left && !right) return this;
        if (left && !right) return left->search(val);
        if (!left && right) return right->search(val);
        return left->val >= val ? left->search(val) : right->search(val);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<Node*> layer;
        for (const int& basket: baskets) {
            layer.push_back(new Node{basket});
        }
        while (layer.size() != 1) {
            vector<Node*> new_layer;
            for (int i = 0; i < layer.size(); i += 2) {
                if (i == layer.size()-1) new_layer.push_back(layer[i]);
                else new_layer.push_back(new Node{layer[i], layer[i+1]});
            }
            layer = new_layer;
        }
        Node* head = layer[0];
        int miss_count = 0;
        for (const int& fruit: fruits) {
            Node* basket = head->search(fruit);
            if (basket->val < fruit) ++miss_count;
            else basket->erase_node();
        }
        return miss_count;
    }
};
// @lc code=end

