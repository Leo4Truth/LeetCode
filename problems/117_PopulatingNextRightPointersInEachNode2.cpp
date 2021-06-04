#include <iostream>
#include <queue>

#include "Node.h"

using namespace std;

class Solution117 {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (i < size - 1) node->next = q.front();
                else node->next = nullptr;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

        }

        return root;
    }

    Node* connect_2(Node* root) {
        if (!root) return nullptr;

        Node* leftmost = root;
        while (leftmost) {
            Node* current = leftmost;
            Node* prev = nullptr;
            leftmost = nullptr;
            while (current) {
                if (current->left) {
                    if (prev) prev->next = current->left;
                    else leftmost = current->left;
                    prev = current->left;
                }

            	if (current->right) {
                    if (prev) prev->next = current->right;
                    else leftmost = current->right;
                    prev = current->right;
            	}

                current = current->next;
            }
        }

        return root;
    }
};