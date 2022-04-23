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
    virtual int minimumRefill(vector<int>& plants, int capacityA, int capacityB) = 0;
};

class Solution_init : public Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        if (n == 0) return 0;

        int i = 0;
        int j = n - 1;
        int a = capacityA;
        int b = capacityB;
        int cntA = 0;
        int cntB = 0;

        while (i < j) {
            if (plants[i] <= a) {
                a -= plants[i];
                i++;
            }
            else {
                cntA++;
                a = capacityA - plants[i];
                i++;
            }
            if (plants[j] <= b) {
                b -= plants[j];
                j--;
            }
            else {
                cntB++;
                b = capacityB - plants[j];
                j--;
            }
        }

        if (i == j) {
            if (a >= b) {
                if (plants[i] <= a) {
                    a -= plants[i];
                    i++;
                }
                else {
                    cntA++;
                    a = capacityA - plants[i];
                    i++;
                }
            }
            else {
                if (plants[j] <= b) {
                    b -= plants[j];
                    j--;
                }
                else {
                    cntB++;
                    b = capacityB - plants[j];
                    j--;
                }
            }
        }
        
        return cntA + cntB;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int a = argc >= 3 ? stoi(argv[2]) : 0;
    int b = argc >= 4 ? stoi(argv[3]) : 0;
    vector<int> plants;
    for (int i = 0; i < n; i++) {
        int plant;
        cin >> plant;
        plants.push_back(plant);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->minimumRefill(plants, a, b) << endl;

    return 0;
}
