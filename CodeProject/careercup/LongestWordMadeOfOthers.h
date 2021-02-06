#pragma once
#include "../Header.h"

class LongestWord {
public:
    static void test() {
        LongestWord obj;
        {
            vector<string> words = { "geeks", "for", "geeksfor", "geeksforgeeks" };
            cout << "Longest Word = " << obj.longestWord(words) << endl;
        }

        {
            vector<string> words = { "Hey", "you", "stop", "right", "there" };
            cout << "Longest Word = " << obj.longestWord(words) << endl;
        }

        {
            vector<string> words = { "cat", "hat", "mat", "catmat","bat","batmatcat","catratmatbat","catmatcatmat","catmatratmapcatmat" };
            cout << "Longest Word = " << obj.longestWord(words) << endl;
        }
    }

    string longestWord(vector<string> words) {
        unordered_map<string, bool> dict;
        for (auto word : words) dict[word] = true;

        sort(words.begin(), words.end(), [](const auto& f, const auto& s) {return f.size() > s.size(); });

        for (auto word : words) {
            if (canBuildFromOtherWordsWithMemoization(word, dict, true)) return word;
        }

        return "";
    }

    bool canBuildFromOtherWords(string word, unordered_map<string, bool> dict, bool org) {
        if (dict.find(word) != dict.end() && !org) return true;
        for (int i = 1; i <= word.length(); i++) {
            string left = word.substr(0, i);
            if (dict.find(left) != dict.end() && canBuildFromOtherWords(word.substr(i), dict, false)) {
                return true;
            }
        }
        return false;
    }

    bool canBuildFromOtherWordsWithMemoization(string word, unordered_map<string, bool>& dict, bool org) {
        if (dict.find(word) != dict.end() && !dict[word]) return false; // if current word has been seen
        if (dict[word] && !org) return true; // if word has been seen already

        if (dict.find(word) != dict.end() && !org && dict[word]) return true; // if not org word and exists in map
        for (int i = 1; i <= word.length(); i++) {
            string left = word.substr(0, i);
            if (dict.find(left) != dict.end() && canBuildFromOtherWords(word.substr(i), dict, false)) {
                dict[word] = true;
                return true;
            }
        }
        dict[word] = false;
        return false;
    }
};