#pragma once
#include "../Header.h"

/*
https://www.careercup.com/question?id=6040159610994688


Find the nearest leaf node from given node in binary tree.

A node might not be an ancestor to its nearest leaf node.
*/
class NearestLeafNodeFromGivenNode
{
public:
    static void test() {
        ITNode* root = new ITNode(1);
        root->left = new ITNode(2);
        root->right = new ITNode(3);
        root->left->left = new ITNode(4);
        root->left->right = new ITNode(5);
        root->left->left->left = new ITNode(6);
        root->left->left->right = new ITNode(7);
        root->left->left->left->left = new ITNode(10);
        root->left->left->left->right = new ITNode(11);
        root->left->left->right->left = new ITNode(12);
        root->left->left->right->right = new ITNode(13);
        root->left->right->left = new ITNode(8);
        root->left->right->right = new ITNode(9);
        root->left->right->left->left = new ITNode(14);
        root->left->right->left->right = new ITNode(15);
        root->left->right->right->left = new ITNode(16);
        root->left->right->right->right = new ITNode(17);

        unordered_map<ITNode*, pair<int, ITNode*>> distanceToNearestLeafNode;
        distanceToLeafNode(root, distanceToNearestLeafNode);

        {
            ITNode* target = root->left;
            unordered_map<ITNode*, int> nodesInPath;
            fillNodesInPath(root, target, nodesInPath);

            auto res = getMinimumDistance(target, nodesInPath, distanceToNearestLeafNode);
            cout << "Nearest leaf node from " << target->val << " is " << res.first->val << " and its distance: " << res.second << endl;
        }

        {
            ITNode* target = root->right;
            unordered_map<ITNode*, int> nodesInPath;
            fillNodesInPath(root, target, nodesInPath);

            auto res = getMinimumDistance(target, nodesInPath, distanceToNearestLeafNode);
            cout << "Nearest leaf node from " << target->val << " is " << res.first->val << " and its distance: " << res.second << endl;
        }

        {
            ITNode* target = root->left->left;
            unordered_map<ITNode*, int> nodesInPath;
            fillNodesInPath(root, target, nodesInPath);

            auto res = getMinimumDistance(target, nodesInPath, distanceToNearestLeafNode);
            cout << "Nearest leaf node from " << target->val << " is " << res.first->val << " and its distance: " << res.second << endl;
        }
    }

    static pair<ITNode*, int> distanceToLeafNode(ITNode* root, unordered_map<ITNode*, pair<int, ITNode*>>& distanceToNearestLeafNode)
    {
        if (!root) return { nullptr,0 };
        if (!root->left && !root->right) {
            distanceToNearestLeafNode.insert({ root, {1,root} });
            return { root,1 };
        }

        auto left = distanceToLeafNode(root->left, distanceToNearestLeafNode);
        auto right = distanceToLeafNode(root->right, distanceToNearestLeafNode);
        ITNode* target = nullptr;
        if (left.second <= right.second)target = left.first;
        else target = right.first;

        distanceToNearestLeafNode.insert({ root, {1 + min(left.second, right.second), target} });

        return { root, 1 + min(left.second, right.second) };
    }

    static int fillNodesInPath(ITNode* root, ITNode* target, unordered_map<ITNode*, int>& nodesInPath)
    {
        if (!root) return INT_MAX;
        if (root == target) {
            nodesInPath.insert({ root,0 });
            return 1;
        }

        int left = fillNodesInPath(root->left, target, nodesInPath);
        int right = fillNodesInPath(root->right, target, nodesInPath);

        if (left != INT_MAX || right != INT_MAX) nodesInPath.insert({ root,1 + min(left,right) });

        return (left != INT_MAX || right != INT_MAX) ? 1 + min(left, right) : INT_MAX;
    }

    static pair<ITNode*, int> getMinimumDistance(ITNode* target, unordered_map<ITNode*, int> nodesInPath,
        unordered_map<ITNode*, pair<int, ITNode*>> distanceToNearestLeafNode)
    {
        int distance = INT_MAX;
        ITNode* result = nullptr;
        for (auto node : nodesInPath) {
            int leafDistance = 0;
            if (target != node.first) leafDistance = node.second + distanceToNearestLeafNode[node.first].first - 1;
            else leafDistance = distanceToNearestLeafNode[node.first].first;

            if (leafDistance < distance) {
                distance = leafDistance;
                result = distanceToNearestLeafNode[node.first].second;
            }
        }

        return { result, distance };
    }
};