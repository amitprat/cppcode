#pragma once
#include "../Header.h"

class SerializeDeserializeTree {
public:
    static void test() {
        ITNode* root = new ITNode(1);
        root->left = new ITNode(2);
        root->right = new ITNode(3);
        root->left->left = new ITNode(4);
        root->right->left = new ITNode(5);
        cout << to_string(root) << endl;

        vector<int> res = serialize(root);
        ITNode* node = deserialize(res);
        cout << to_string(node) << endl;
    }

    static void serialize(ITNode* root, vector<int>& res) {
        if (!root) {
            res.push_back(INT_MIN);
            return;
        }

        res.push_back(root->val);

        serialize(root->left, res);
        serialize(root->right, res);
    }

    static ITNode* deserialize(vector<int>& res, int& index) {
        if (index >= res.size()) return nullptr;

        auto cur = res[index++];
        if (cur == INT_MIN) return nullptr;

        auto root = new ITNode(cur);
        root->left = deserialize(res, index);
        root->right = deserialize(res, index);

        return root;
    }

    static vector<int> serialize(ITNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<ITNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur == nullptr) result.push_back(INT_MIN);
            else result.push_back(cur->val);

            if (cur != nullptr) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return result;
    }

    static ITNode* deserialize(vector<int> result) {
        if (result.empty()) return nullptr;
        queue<ITNode*> q;
        int index = 0;
        ITNode* root = new ITNode(result[index++]);
        q.push(root);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            auto val = result[index++];
            cur->left = val != INT_MIN ? new ITNode(val) : nullptr;

            val = result[index++];
            cur->right = val != INT_MIN ? new ITNode(val) : nullptr;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        return root;
    }
};