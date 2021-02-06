#include "../Header.h"

/*
Given a BST and a value x. Find two nodes in the tree whose sum is equal x. Additional space: O(height of the tree). It is not allowed to modify the tree
*/
class FindPair {
    struct Node {
        int val;
        Node* left, * right;
        Node(int val) :val(val), left(nullptr), right(nullptr) {}
        string to_string() {
            return std::to_string(val);
        }
    };
public:
    static void test() {
        FindPair obj;
        Node* root = new Node(5);
        root->left = new Node(3);
        root->right = new Node(7);
        root->left->left = new Node(2);
        root->left->right = new Node(4);
        root->right->left = new Node(6);
        root->right->right = new Node(8);
        int target = 10;

        auto res = obj.findPairUsingDLL(root, target);
        for (auto e : res) {
            cout << "{" + std::to_string(e.first) + "," + std::to_string(e.second) + "}" << endl;
        }
    }

    vector<pair<int, int>> findPairUsingSet(Node* root, int target) {
        unordered_set<int> set;
        vector<pair<int, int>> res;

        findPairUsingSet(root, target, set, res);

        return res;
    }

    vector<pair<int, int>> findPairsUsingStack(Node* root, int target) {
        stack<Node*> leftSt, rightSt;
        Node* leftNode = root, * rightNode = root;
        vector<pair<int, int>> result;
        while (true) {
            while (leftNode) { leftSt.push(leftNode); leftNode = leftNode->left; }
            while (rightNode) { rightSt.push(rightNode); rightNode = rightNode->right; }
            if (leftSt.empty() || rightSt.empty()) break;
            auto val1 = leftSt.top(); leftSt.pop();
            auto val2 = rightSt.top(); rightSt.pop();
            if (val1->val >= val2->val) break;
            if (val1->val + val2->val == target) result.push_back({ val1->val , val2->val });
            leftNode = val1->right;
            rightNode = val2->left;
        }
        return result;
    }

    vector<pair<int, int>> findPairUsingDLL(Node* root, int target) {
        auto res = convertToDLL(root);
        vector<pair<int, int>> result;
        while (res.first != res.second) {
            auto cur = res.first->val + res.second->val;
            if (cur == target) {
                result.push_back({ res.first->val , res.second->val });
                res.first = res.first->right;
                res.second = res.second->left;
            }
            else if (cur < target) res.first = res.first->right;
            else res.second = res.second->left;
        }
        return result;
    }

private:
    void findPairUsingSet(Node* root, int target, unordered_set<int>& set, vector<pair<int, int>>& res) {
        if (root) {
            findPairUsingSet(root->left, target, set, res);
            if (set.find(target - root->val) != set.end()) {
                res.push_back({ target - root->val, root->val });
            }
            set.insert(root->val);
            findPairUsingSet(root->right, target, set, res);
        }
    }

    pair<Node*, Node*> convertToDLL(Node* root) {
        Node* first = nullptr, * last = nullptr;
        convertToDLL(root, first, last);

        return { first,last };
    }

    void convertToDLL(Node* root, Node*& first, Node*& last) {
        if (root) {
            static Node* prev = nullptr;
            convertToDLL(root->left, first, last);
            if (prev == nullptr) first = root;
            else {
                root->left = prev;
                prev->right = root;
            }
            last = root;
            prev = root;
            convertToDLL(root->right, first, last);
        }
    }
};
/*
solution : having complexity O(n)(time)+O(height of BST)(space)
observation : if we are given a sorted array instead of a BST and the same question was asked then so solve this problem in O(n)+O(1) complexity, we keep two indexes one at start and 2nd one at end, and apply following algo.


if(A[1st_index] + A[2nd_index] < x)
    2nd_index--;
else if (A[1st_index] + A[2nd_index] > x)
    1st_index++;
else
     print 1st_index,2nd_index;
do this until 2nd_index > 1st_index
so we apply the same concept here, because we don't have data stored in an array faction, so we need some space, now one way is tot store the data into an array and apply the same, but this require O(n) space, but if you think carefully, then we only require at max 2*height_of_BST, in first array of size height_of_BST, we store all elements which comes from


root->left,root->left->left,.......
and in 2nd array we store


root,root->right,root->right->right,.......
and we start with the last element of these two array, these array's are actually stack. now we get two element do we do the same comparison here also


if(first_stack_element + 2nd_stack_element < x)
    check for it's left tree, and store all right going element into stack(2nd stack) and start again
    example :
     \
      6
     /
   3
  / \
  1  4
  so we store [.......3,4] after popging 6. because now 4 is the biggest element in the tree.
  actually we search for last biggest element here.
else if (first_stack_element + 2nd_stack_element > x)
    Here we search for next smallest element, using our 1st stack.
   example
    /
   2
    \
      6
    /  \
   3   7
now here we go with 3 for next comparison.and the stack contain [.....,6,3] after popping 2
 else
     print first_stack_element, 2nd_stack_element;
do this until first_stack_element < 2nd_stack_element
*/