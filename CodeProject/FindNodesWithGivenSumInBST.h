#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic> 
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <algorithm> 
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;

template <class K, class V>
struct Node {
    K key;
    V val;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(K key, V val) : key(key), val(val) {}
};

template <class K, class V>
class BinarySearchTree
{
private:

public:
    Node<K, V>* root = nullptr;
    BinarySearchTree() {}
    BinarySearchTree(vector<pair<K, V>> vals)
    {
        for (auto val : vals) {
            root = insert(root, val.first, val.second);
        }
    }

    Node<K, V>* insert(Node<K, V>* root, K key, V val) {
        if (!root) {
            root = new Node<K, V>(key, val); return root;
        }
        if (key < root->key) root->left = insert(root->left, key, val);
        else if (key > root->key) root->right = insert(root->right, key, val);
        else root->val = val;

        return root;
    }

    string to_string() {
        stringstream ss;
        Node<K, V>* tmp = root;
        to_string(tmp, ss);

        return ss.str();
    }

    void to_string(Node<K, V>* tmp, stringstream& ss) {
        if (tmp) {
            to_string(tmp->left, ss);
            ss << "{" << tmp->key << ":" << tmp->val << "}";
            ss << ", ";
            to_string(tmp->right, ss);
        }
    }
};
class FindNodesWithGivenSuminBST
{
public:
    static void test()
    {
        FindNodesWithGivenSuminBST obj;
        BinarySearchTree<int, int> bst1({ {1,2},{2,3},{2,3},{5,3},{2,5},{0,1},{8,4} });
        BinarySearchTree<int, int> bst2({ {13,20},{1,4},{0,9},{5,7},{1,6},{9,10},{11,4} });
        cout << "BST1: " << bst1.to_string() << endl;
        cout << "BST2: " << bst1.to_string() << endl;

        for (int sum = 0; sum < 50; sum++) {
            auto res = obj.findPairWithSum(bst1, sum);
            string strres = "{" + to_string(res.first) + ", " + to_string(res.second) + "}";
            cout << "Found sum  = " << sum << " : " << strres.c_str() << endl;
        }
    }

    pair<int, int> findPairWithSum(BinarySearchTree<int, int> bst1, int sum)
    {
        stack<Node<int, int>*> stack1;
        stack<Node<int, int>*> stack2;

        Node<int, int>* left = bst1.root;
        Node<int, int>* right = bst1.root;
        bool checkLeft = true;
        bool checkRight = true;

        while (true) {
            while (left && checkLeft) {
                stack1.push(left);
                left = left->left;
            }
            checkLeft = false;

            while (right && checkRight) {
                stack2.push(right);
                right = right->right;
            }
            checkRight = false;

            if (!left && !stack1.empty()) {
                left = stack1.top(); stack1.pop();
            }
            if (!right && !stack2.empty()) {
                right = stack2.top(); stack2.pop();
            }
            if (!left || !right || left->key >= right->key) return { -1,-1 };
            int cursum = left->key + right->key;
            if (sum == cursum) return { left->key , right->key };
            else if (cursum < sum) {
                left = left->right;
                checkLeft = true;
            }
            else {
                right = right->left;
                checkRight = true;
            }
        }

        return { -1,-1 };
    }
};