#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 构造前缀树节点
class Trie {
public:
    int val;
    vector<Trie*> children;
    Trie () : val(0), children(26, nullptr) {}

    // 实现插入字符串
    void insert(string& str, int m) {
        Trie* node = this;
        for (auto& ch : str) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->val = m;
    }

    // 实现返回所有以该前缀 prefix 开头的键 key 的值的总和
    int coutSum(string &prefix) {
        Trie* node = this;
        for (auto& ch : prefix) {
            if (node->children[ch - 'a'] == nullptr) {
                return 0;
            }
            node = node->children[ch - 'a'];
        }

        // BFS
        int count = 0;
        queue<Trie*> que;
        que.push(node);
        while (!que.empty()) {
            Trie* node = que.front();
            que.pop();
            count += node->val;
            for (int i = 0; i < node->children.size(); ++i) {
                if (node->children[i] != nullptr) {
                    que.push(node->children[i]);
                }
            }
        }
        return count;
    }
};

class MapSum {
private:
    Trie* root;
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        root->insert(key, val);
    }
    
    int sum(string prefix) {
        return root->coutSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(int argc, char* argv[]) {
    MapSum mapSum;

    string op;
    cin >> op;
    while (op.compare("exit") != 0) {
        if (op.compare("insert") == 0) {
            string key;
            int val;
            cin >> key >> val;
            mapSum.insert(key, val);
        } else if (op.compare("sum") == 0) {
            string prefix;
            cin >> prefix;
            cout << mapSum.sum(prefix) << endl;
        }
        cin >> op;
    }

    return 0;
}
