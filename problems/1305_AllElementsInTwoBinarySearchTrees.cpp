#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

// #define DEBUG

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    virtual vector<int> getAllElements(TreeNode* root1, TreeNode* root2) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1 = getNumsFromBST(root1);
        vector<int> nums2 = getNumsFromBST(root2);
        vector<int> nums;
        int n1 = nums1.size(), n2 = nums2.size();
#ifdef DEBUG
        cout << "n1: " << n1 << endl;
        cout << "n2: " << n2 << endl;
#endif
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        for (; i < n1; i++) nums.push_back(nums1[i]);
        for (; j < n2; j++) nums.push_back(nums2[j]);
        return nums;
    }

private:
    vector<int> getNumsFromBST(TreeNode* root) {
        if (!root) {
#ifdef DEBUG
            cout << "[]" << endl;
#endif
            return {};
        }

        vector<int> nums;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (!stk.empty() || cur) {
            // 沿着当前节点cur的左分支一直走到底
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            TreeNode* node = stk.top();
            stk.pop();
            nums.push_back(node->val);
            cur = node->right;
        }
        
#ifdef DEBUG
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
#endif
        
        return nums;
    }
};

int main(int argc, char* argv[]) {
    /**
     * @brief case 1
     *      2      1
     *     / \    / \
     *    1   4  0   3
     */

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* m1 = new TreeNode(1);
    TreeNode* m2 = new TreeNode(0);
    TreeNode* m3 = new TreeNode(3);

    n2->left = n1;
    n2->right = n3;
    m1->left = m2;
    m1->right = m3;

    /**
     * @brief case 2
     *      5
     *     / \
     *    1   7
     *   / \
     *  0   2
     */

    TreeNode* n4 = nullptr;
    TreeNode* m4 = new TreeNode(5);
    TreeNode* m5 = new TreeNode(1);
    TreeNode* m6 = new TreeNode(7);
    TreeNode* m7 = new TreeNode(0);
    TreeNode* m8 = new TreeNode(2);

    m4->left = m5;
    m4->right = m6;
    m5->left = m7;
    m5->right = m8;

    Solution *solution = nullptr;

    solution = new Solution_init();

    cout << "case 1: " << endl;
    vector<int> nums = solution->getAllElements(n2, m1);
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "case 2: " << endl;
    nums = solution->getAllElements(n4, m4);
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
