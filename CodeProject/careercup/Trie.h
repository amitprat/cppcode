#pragma once
#include "../Header.h"

class Trie
{
    class Node
    {
    public:
        bool end;
        unordered_map<char, Node *> children;
        Node(bool end = false) : end(end) {}
    };
    Node *root = nullptr;

public:
    void insert(string str)
    {
        root = insert(root, str, 0);
    }
    void remove(string str)
    {
        remove(root, str, 0);
    }
    bool contains(string str)
    {
        return contains(root, str, 0);
    }
    void traverse()
    {
        traverse(root, "");
    }
    vector<string> prefix(string str)
    {
        vector<string> result;
        prefix(root, str, 0, result);
        return result;
    }
    static void test()
    {
        Trie trie;
        auto insertLog = [&trie](string item)
        {
            cout << "Inserting: " << item;
            trie.insert(item);
            cout << endl;
        };
        auto removeLog = [&trie](string item)
        {
            cout << "Deleting: " << item;
            trie.remove(item);
            cout << endl;
        };
        auto traverseLog = [&trie]()
        {
            cout << "Traversing Trie: ";
            trie.traverse();
            cout << endl;
        };
        auto containsLog = [&trie](string str)
        {
            cout << "Does contains (" << str << ") = ";
            cout << (trie.contains(str) ? "True" : "False") << endl;
            cout << endl;
        };

        insertLog("I");
        insertLog("Am");
        insertLog("Amit");

        traverseLog();
        containsLog("I");
        containsLog("i");
        containsLog("am");
        containsLog("Am");
        containsLog("Amit");
        containsLog("IAmAmit");
        cout << to_string(trie.prefix("AmitSingh")) << endl;

        removeLog("Am");
        traverseLog();
        containsLog("I");
        containsLog("i");
        containsLog("am");
        containsLog("Am");
        containsLog("Amit");
        containsLog("IAmAmit");

        insertLog("Am");
        removeLog("Amit");
        traverseLog();
        containsLog("I");
        containsLog("i");
        containsLog("am");
        containsLog("Am");
        containsLog("Amit");
        containsLog("IAmAmit");
    }

private:
    Node *insert(Node *cur, string str, int l)
    {
        if (cur == nullptr)
            cur = new Node();
        if (l == str.length())
        {
            cur->end = true;
            return cur;
        }

        cur->children[str[l]] = insert(cur->children[str[l]], str, l + 1);
        return cur;
    }
    bool remove(Node *&cur, string str, int l)
    {
        if (cur == nullptr)
            return false;
        if (l == str.length())
        {
            cur->end = false;
            return isLeaf(cur);
        }
        if (remove(cur->children[str[l]], str, l + 1))
        {
            delete cur->children[str[l]];
            cur->children.erase(str[l]);
            return isLeaf(cur);
        }
        return false;
    }
    bool contains(Node *cur, string str, int l)
    {
        if (cur == nullptr)
            return false;
        if (l == str.length())
            return cur->end;

        return contains(cur->children[str[l]], str, l + 1);
    }
    void traverse(Node *cur, string prefix)
    {
        if (cur)
        {
            if (cur->end)
            {
                cout << prefix << " ";
            }
            for (auto child : cur->children)
            {
                traverse(child.second, prefix + child.first);
            }
        }
    }
    void prefix(Node *cur, string str, int l, vector<string> &result)
    {
        if (l == str.length())
        {
            result.push_back(str);
            return;
        }
        if (cur == nullptr)
        {
            result.push_back(str.substr(0, l - 1));
            return;
        }
        if (cur->end)
            result.push_back(str.substr(0, l));

        prefix(cur->children[str[l]], str, l + 1, result);
    }
    bool isLeaf(Node *cur)
    {
        return cur->end && cur->children.empty();
    }
};