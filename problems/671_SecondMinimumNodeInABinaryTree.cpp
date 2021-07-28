#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>

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
    // DFS 
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        long long min = (long long)INT32_MAX + 1;
        long long secondMin = (long long)INT32_MAX + 2;
        TreeNode* p = root;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
                // dfs visit
#ifdef DEBUG
                cout << "visit " << node->val << endl;
#endif // DEBUG
                if ((long long)p->val < min) {
                    secondMin = min;
                    min = (long long)p->val;
                }
                else if ((long long)p->val > min && (long long)p->val < secondMin) {
                    secondMin = (long long)p->val;
                }
                p = p->right;
            }
        }
        if (secondMin == (long long)INT32_MAX + 2 || secondMin == (long long)INT32_MAX + 1) return -1;
        return (int)secondMin;
    }

    // Official Solution, DFS
    int findSecondMinimumValue_offcial(TreeNode* root) {
        int ans = -1;
        int rootvalue = root->val;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            if (ans != -1 && node->val >= ans) {
                return;
            }
            if (node->val > rootvalue) {
                ans = node->val;
            }
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(5);
    TreeNode* n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    Solution solution;
    cout << solution.findSecondMinimumValue(n1) << endl;

    //system("pause");
    return 0;
}
