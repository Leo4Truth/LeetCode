#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }

    Node* treeToDoublyList_nonrecursive(Node* root) {
        if (!root) return nullptr;
        stack<Node*> stk;
        Node* current = root;
        while (current || !stk.empty()) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            if (!stk.empty()) {
                current = stk.top();
                stk.pop();
                if (!prev) head = current;
                else prev->right = current;
                current->left = prev;
                prev = current;
                current = current->right;
            }
        }
        prev->right = head;
        head->left = prev;
        return head;
    }

private:
    Node* head = nullptr;
    Node* prev = nullptr;
    void dfs(Node* current) {
        if (!current) return;
        dfs(current->left);
        if (prev) prev->right = current;
        else head = current;
        current->left = prev;
        prev = current;
        dfs(current->right);
    }
};

int main(int argc, char* argv[]) {
    Node* n1 = new Node(0);
    Node* n2 = new Node(1);
    Node* n3 = new Node(2);
    Node* n4 = new Node(3);
    Node* n5 = new Node(4);

    n3->left = n2;
    n2->left = n1;
    n3->right = n5;
    n5->left = n4;

    Solution solution;
    Node* head = solution.treeToDoublyList(n3);

    Node* p = head;
    for (int i = 0; i < 5; i++) {
        cout << p->val << " ";
        p = p->right;
    }
    cout << endl;

    //system("pause");
    return 0;
}
