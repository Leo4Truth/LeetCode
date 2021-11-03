#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TNode {
    int val;
    vector<TNode*> children;
    TNode(int x) : val(x) {};
};

class Solution582 {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        if (n == 0) return {};

        TNode* root = new TNode(0);
        unordered_map<int, TNode*> pid2node;
        unordered_map<int, int> pid2idx; 
        TNode* target = nullptr;
        pid2node[0] = root;
        for (int i = 0; i < n; i++) {
            pid2idx[pid[i]] = i;
            TNode* node = nullptr;
            if (pid2node.count(pid[i]) > 0) node = pid2node[pid[i]];
            else node = new TNode(pid[i]);
            pid2node[pid[i]] = node;

            if (kill == pid[i]) target = node;

            if (pid2node.count(ppid[i]) > 0) pid2node[ppid[i]]->children.push_back(node);
            else {
                TNode* pnode = new TNode(ppid[i]);
                pid2node[ppid[i]] = pnode;
                pnode->children.push_back(node);
            }
        }

        print(root);

        vector<int> res;
        queue<TNode*> q;
        q.push(target);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
            for (auto child : node->children) q.push(child);
        }
        return res;
    }

    void print(TNode* root) {
        if (root) {
            cout << root->val << endl;
            for (auto child : root->children) print(child);
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int kill = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> pid;
    vector<int> ppid;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pid.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ppid.push_back(x);
    }

    Solution582 solution;
    vector<int> res = solution.killProcess(pid, ppid, kill);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;

    //system("pause");
    return 0;
}

