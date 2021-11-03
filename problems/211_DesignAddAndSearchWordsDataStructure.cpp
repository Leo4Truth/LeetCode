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
    bool isEnd;
    TrieNode() {
        this->children = vector<TrieNode*>(26, nullptr);
        this->isEnd = false;
    }
};

class WordDictionary {
public:
    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

private:
    TrieNode *root;

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool dfs(TrieNode* root, const string& word, int index) {
        if (index == word.size()) return root->isEnd;
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode* child = root->children[ch - 'a'];
            if (child && dfs(child, word, index + 1)) return true;
        } else if (ch == '.') {
            for (auto& child : root->children) {
                if (child && dfs(child, word, index + 1)) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char* argv[]) {
    WordDictionary* wordDictionary = new WordDictionary();
    
    string op = "";
    string word = "";
    cin >> op >> word;
    while (op.compare("exit") != 0) {
        if (op.compare("add")) {
            wordDictionary->addWord(word);
        } else if (op.compare("search")) {
            cout << wordDictionary->search(word) << endl;
        }
        cin >> op >> word;
    }
    
    return 0;
}
