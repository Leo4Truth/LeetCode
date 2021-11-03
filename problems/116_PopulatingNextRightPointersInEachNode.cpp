#include <iostream>
#include <queue>

#include "Node.h"

using namespace std;

class Solution116 {
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
    	while (leftmost->left) {
            Node* head = leftmost;
    		while (head) {
                // connection 1
    			head->left->next = head->right;

    			// connection 2
    			// based on the connection 1 between head and head->next established by head's parent
                if (head->next) head->right->next = head->next->left;

                head = head->next;
    		}
            leftmost = leftmost->left;
    	}

        return root;
    }
};