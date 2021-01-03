#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<int> &current, vector<bool> & used, int &cnt) {
        int n = used.size();
        int i = current.size() + 1;
        if (i == n + 1) {
            //print(current);
            cnt++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!used[j] && ((j+1) % i == 0 || i % (j+1) == 0)) {
                used[j] = true;
                current.push_back(j+1);
                backtrack(current, used, cnt);
                current.pop_back();
                used[j] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> current;
        vector<bool> used(n, false);
        int cnt = 0;
        backtrack(current, used, cnt);
        return cnt;
    }

    void print(vector<int> nums) {
        cout << "[ ";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
};

int main(int argc, char *argv[]) {
    int n;
    if (argc == 2) n = stoi(argv[1]);
    else {
        cout << "please input n: ";
        cin >> n;
    }

    Solution solution;

    cout << solution.countArrangement(n) << endl;

    return 0;
}
