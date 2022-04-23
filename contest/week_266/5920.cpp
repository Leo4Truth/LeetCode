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
    virtual int minimizedMaximum(int n, vector<int>& quantities) = 0;
};

class Solution_binarySearch : public Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int lo = 1, hi = *max_element(quantities.begin(), quantities.end());
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            long long need = 0;
            for (int q : quantities)
                need += (q - 1) / mid + 1;
            if (need > n)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> quantities;
    for (int i = 0; i < m; i++) {
        int quantity;
        cin >> quantity;
        quantities.push_back(quantity);
    }

    Solution *solution = nullptr;

    solution = new Solution_binarySearch();
    cout << solution->minimizedMaximum(n, quantities) << endl;

    return 0;
}
