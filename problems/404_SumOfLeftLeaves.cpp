#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q1;
        queue<bool> q2; // isLeft ?
        int sum = 0;

        q1.push(root);
        q2.push(false);
        while (!q1.empty()) {
            TreeNode* p = q1.front();
            q1.pop();
            bool isLeft = q2.front();
            q2.pop();
            
            if (isLeft && !p->left && !p->right) sum += p->val;

            if (p->left) {
                q1.push(p->left);
                q2.push(true);
            }
            if (p->right) {
                q1.push(p->right);
                q2.push(false);
            }
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    TreeNode* nn1 = new TreeNode(1);
    TreeNode* nn2 = new TreeNode(2);
    TreeNode* nn3 = new TreeNode(3);
    TreeNode* nn4 = new TreeNode(4);
    TreeNode* nn5 = new TreeNode(5);

    nn1->left = nn2;
    nn1->right = nn3;
    nn2->left = nn4;
    nn2->right = nn5;

    Solution solution;
    cout << solution.sumOfLeftLeaves(n1) << endl;
    cout << solution.sumOfLeftLeaves(nn1) << endl;

    //system("pause");
    return 0;
}
