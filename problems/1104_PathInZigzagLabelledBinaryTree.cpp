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
    // TODO
    vector<int> pathInZigZagTree(int label) {
        int numOfRow = getLevels(label);
        vector<int> path;
        for (int row = numOfRow - 1; row >= 0; row--) {
            if (row % 2 == 0) {
                
            }
            else {
                
            }
        }
        return {};
    }

    int getLevels(int n) {
        if (n == 0) return {};
        int numOfRow = 0;
        int nodeInRow = 1;
        while (n > 0) {
            n -= nodeInRow;
            nodeInRow *= 2;
            numOfRow++;
        }
        return numOfRow;
    }

    // Official Solution
    vector<int> pathInZigZagTree(int label) {
        int row = 1, rowStart = 1;
        while (rowStart * 2 <= label) {
            row++;
            rowStart *= 2;
        }
        if (row % 2 == 0) {
            label = getReverse(label, row);
        }
        vector<int> path;
        while (row > 0) {
            if (row % 2 == 0) {
                path.push_back(getReverse(label, row));
            } else {
                path.push_back(label);
            }
            row--;
            label >>= 1;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    int getReverse(int label, int row) {
        return (1 << row - 1) + (1 << row) - 1 - label;
    }
};

int main(int argc, char* argv[]) {
    int label = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    vector<int> res = solution.pathInZigZagTree(label);
    for (auto x : res) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
