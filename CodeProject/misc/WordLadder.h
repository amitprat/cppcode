#pragma once

#include <time.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>
#include <time.h>
#include <fstream>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <algorithm>
using namespace std;

class WordLadder
{
private:
    //MemoryEfficientTrie trie;

public:
    static void test() {
        WordLadder obj;
        {
            string beginWord = "hit";
            string endWord = "cog";
            unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log", "cog" };
            //unordered_set<string> dict = { "poon", "plee", "same", "poie", "plie", "poin", "plea" };

            auto result = obj.findShortestPath(beginWord, endWord, dict);
            print(result);

            cout << obj.ladderLength(beginWord, endWord, dict) << endl;
            cout << obj.findLadderBidirection(beginWord, endWord, dict) << endl;
        }
        {
            string beginWord = "poon";
            string endWord = "plea";
            unordered_set<string> dict = { "poon", "plee", "same", "poie", "plie", "poin", "plea" };

            auto result = obj.findShortestPath(beginWord, endWord, dict);
            print(result);

            cout << obj.ladderLength(beginWord, endWord, dict) << endl;
            cout << obj.findLadderBidirection(beginWord, endWord, dict) << endl;
        }
        {
            string beginWord = "poon";
            string endWord = "same";
            unordered_set<string> dict = { "poon", "plee", "same", "poie", "plie", "poin", "plea" };

            auto result = obj.findShortestPath(beginWord, endWord, dict);
            print(result);

            cout << obj.ladderLength(beginWord, endWord, dict) << endl;
            cout << obj.findLadderBidirection(beginWord, endWord, dict) << endl;
        }
        {
            string beginWord = "poon";
            string endWord = "hell";
            unordered_set<string> dict = { "poon", "plee", "same", "poie", "plie", "poin", "plea" };

            auto result = obj.findShortestPath(beginWord, endWord, dict);
            print(result);

            cout << obj.ladderLength(beginWord, endWord, dict) << endl;
            cout << obj.findLadderBidirection(beginWord, endWord, dict) << endl;
        }
    }

    static void print(vector<string>& result) {
        for (auto& s : result) cout << s << " ";
        cout << endl;
    }

    //void preprocess(vector<string>& words) {
    //    for (auto& s : words) trie.insert(s);
    //}

    vector<string> findShortestPath(string& begin, string& end, unordered_set<string>& dict) {
        queue <pair<string, vector<string>>> q;
        q.push({ begin, {begin} });
        unordered_set<string> visited;
        vector<string> res;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front(); q.pop();
                if (cur.first == end) {
                    res = cur.second; break;
                }
                visited.insert(cur.first);

                auto neighbours = getOneDistantWords(cur.first, dict, visited);
                for (auto neighbour : neighbours) {
                    auto tmp = cur.second;
                    tmp.push_back(neighbour);
                    q.push({ neighbour,tmp });
                    visited.insert(neighbour);
                }
            }
        }
        cout << res.size() << endl;
        return res;
    }

    vector<string> getOneDistantWords(string begin, unordered_set<string>& dict, unordered_set<string>& visited) {
        vector<string> res;
        for (int i = 0; i < begin.length(); i++) {
            char tmp = begin[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (begin[i] != ch) {
                    begin[i] = ch;
                    if (dict.find(begin) != dict.end() && visited.find(begin) == visited.end()) res.push_back(begin);
                }
            }
            begin[i] = tmp;
        }

        return res;
    }

    int ladderLength(string& begin, string& end, unordered_set<string>& dict) {
        queue<string> q;
        q.push(begin);
        int len = 1;
        // if end word isn't present in dict, insert in dict

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto cur = q.front(); q.pop();
                if (cur == end) return len;
                dict.erase(cur);

                vector<string> neighbours = getOneDistantWords(cur, dict);
                for (auto neighbour : neighbours) {
                    q.push(neighbour);
                }
            }
            len++;
        }

        return 0;
    }

    vector<string> getOneDistantWords(string word, unordered_set<string> dict) {
        vector<string> neighbours;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            for (char t = 'a'; t <= 'z'; t++) {
                word[i] = t;
                if (dict.contains(word)) neighbours.push_back(word);
            }
            word[i] = ch;
        }
        return neighbours;
    }

    int findLadderBidirection(string begin, string end, unordered_set<string>& dict) {
        unordered_set<string> head, tail;
        unordered_set<string>* phead, * ptail;
        head.insert(begin);
        tail.insert(end);
        int ladder = 2;

        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> tmp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                vector<string> neighbours = getOneDistantWords(*it, dict);
                for (auto neighbour : neighbours) {
                    if (ptail->find(neighbour) != ptail->end()) {
                        return ladder;
                    }
                    tmp.insert(neighbour);
                    dict.erase(neighbour);
                }
            }
            ladder++;
            phead->swap(tmp);
        }
        return 0;
    }
};