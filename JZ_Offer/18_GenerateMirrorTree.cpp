#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* Mirror(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = Mirror(root->right);
        root->right = Mirror(tmp);
        return root;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    TreeNode* root = n1;

    Solution solution;
    TreeNode* res = solution.Mirror(root);

    //system("pause");
    return 0;
}
