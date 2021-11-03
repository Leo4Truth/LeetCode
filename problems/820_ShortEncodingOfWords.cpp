#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    int count;
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        count = 0;
    }
    
    TrieNode* get(char c) {
        if (!children[c - 'a']) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};

class Solution820 {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        unordered_set<string> hashSet;

        for (auto word : words) hashSet.insert(word);
        for (auto word : words) {
            int len = word.size();
            for (int i = 1; i < len; i++) {
                if (hashSet.find(word.substr(i)) != hashSet.end())
                    hashSet.erase(hashSet.find(word.substr(i)));
            }
        }

        string code = "";
        for (auto word : hashSet) code.append(word + "#");

        return code.length();
    }

    int minimumLengthEncoding_trie(vector<string>& words) {
        int n = words.size();

        TrieNode* root = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            TrieNode* current = root;
            int len = word.size();
            // NOTICE: Here we use inverse order
            for (int j = len - 1; j >= 0; j--) current = current->get(word[j]);
            nodes[current] = i;
        }

        int res = 0;
        for (auto p : nodes) {
            if (p.first->count == 0) {
                res += words[nodes[p.first]].size() + 1;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution820 solution;
    cout << solution.minimumLengthEncoding_trie(words) << endl;

    return 0;
}

