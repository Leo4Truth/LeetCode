#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

// Definition for a Trie Node.
struct TrieNode {
    int val;
    TrieNode * next[26];
    TrieNode() {
        this->val = 0;
        for (int i = 0; i < 26; ++i) {
            this->next[i] = nullptr;
        }
    }
};

class Solution {
public:
    virtual int method() = 0;
};

class Solution_init : public Solution {
public:
    int method() {
        
        return 0;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();

    return 0;
}
