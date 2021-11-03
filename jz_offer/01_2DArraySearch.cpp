#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if (m == 0) return false;
        int n = array[0].size();
        if (n == 0) return false;
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (target == array[r][c]) return true;
            else if (target > array[r][c]) ++r;
            else --c;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int target = argc > 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    int n = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> array;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        array.push_back(row);
    }

    Solution solution;
    cout << solution.Find(target, array) << endl;

    //system("pause");
    return 0;
}

