#pragma once
#include "../header.h"

template <class T>
class TreeNode {
public:
    T val;
    TreeNode* left, * right;
    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
};

class LeastCommonAncestor {
public:
    static void test() {
        LeastCommonAncestor obj;
        TreeNode<int>* tree = new TreeNode<int>(1);
        tree->left = new TreeNode<int>(2);
        tree->left->left = new TreeNode<int>(3);
        tree->left->left->left = new TreeNode<int>(4);
        tree->left->left->left->right = new TreeNode<int>(5);
        tree->right = new TreeNode<int>(6);
        tree->right->left = new TreeNode<int>(7);
        tree->right->left->right = new TreeNode<int>(8);
        tree->right->right = new TreeNode<int>(9);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                auto* node = obj.findLCA(tree, i, j);
                if (node == nullptr) cout << "No LCA for " << i << ", " << j << " exists." << endl;
                else cout << "LCA for " << i << ", " << j << " is " << node->val << endl;
            }
        }
    }

    TreeNode<int>* findLCA(TreeNode<int>* root, int node1, int node2) {
        TreeNode<int>* left = nullptr;
        TreeNode<int>* right = nullptr;
        return findLCA(root, node1, node2, left, right);
    }

private:
    TreeNode<int>* findLCA(TreeNode<int>* root, int node1, int node2, TreeNode<int>*& node1Node, TreeNode<int>*& node2Node) {
        if (root == nullptr) return root;
        if (root->val == node1) { node1Node = root; }
        if (root->val == node2) { node2Node == root; }
        if (node1Node && node2Node) return root;

        auto* left = findLCA(root->left, node1, node2, node1Node, node2Node);
        if (left) return left;
        auto* right = findLCA(root->right, node1, node2, node1Node, node2Node);
        if (right) return right;

        return nullptr;
    }
};