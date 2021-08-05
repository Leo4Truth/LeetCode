#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

};

int main(int argc, char* argv[]) {
    int n1 = argc >= 2 ? stoi(argv[1]) : 0;
    int n2 = argc >= 3 ? stoi(argv[2]) : 0;
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;
    
    return 0;
}
