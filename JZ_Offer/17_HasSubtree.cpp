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
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        if (pRoot1->val == pRoot2->val)
            return isSubtree(pRoot1->left, pRoot2->left) && 
                   isSubtree(pRoot1->right, pRoot2->right);
        return false;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        return isSubtree(pRoot1, pRoot2) || 
               HasSubtree(pRoot1->left, pRoot2) || 
               HasSubtree(pRoot1->right, pRoot2);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);

    TreeNode* m1 = new TreeNode(11);
    TreeNode* m2 = new TreeNode(12);
    TreeNode* m3 = new TreeNode(13);

    TreeNode* pRoot1 = nullptr;
    TreeNode* pRoot2 = nullptr;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    m1->left = m2;
    m1->right = m3;
    n3->right = m1;
    m3->left = n6;

    pRoot1 = n1;
    pRoot2 = m1;

    Solution solution;
    cout << solution.HasSubtree(pRoot1, pRoot2) << endl;

    //system("pause");
    return 0;
}
