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

class Solution {
public:
    virtual vector<int> canSeePersonsCount(vector<int>& heights) = 0;
};

/**
 * @brief 遍历, 对每个位置, 向右用单调栈统计能看到的人的数量
 * 超过时间限制
 */
class Solution_init : public Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return {};
        if (n == 1) return {0};
        vector<int> visible(n, 1);
        for (int i = 0; i < n; i++) {
            stack<int> stk;
            for (int j = i + 1; j < n; j++) {
                if (stk.empty() || heights[j] >= stk.top()) {
                    stk.push(heights[j]);
                    if (stk.top() >= heights[i]) break;
                }
            }
            visible[i] = stk.size();
        }
        return visible;
    }

private:
};

/**
 * @brief 逆序遍历 + 单调栈
 */
class Solution_reverse_Traversal_with_mono_stack : public Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return {};
        if (n == 1) return {0};
        vector<int> visible(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty()) {
                visible[i]++;
                if (heights[i] > stk.top()) stk.pop();
                else break;
            }
            stk.push(heights[i]);
        }
        return visible;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        heights.push_back(height);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    vector<int> visible = solution->canSeePersonsCount(heights);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << visible[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution = new Solution_reverse_Traversal_with_mono_stack();
    visible = solution->canSeePersonsCount(heights);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << visible[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
