#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;

        vector<int> nums(2, 0);
        nums[0] = 0;
        nums[1] = 1;

#ifdef DEBUG
        cout << nums[0] << ", " << nums[1] << ", ";
#endif // DEBUG

        int max = 0;
        for (int i = 2; i <= n; i++) {
            int ii = i / 2;
            nums.push_back(0);
            if (i % 2 == 0) nums[i] = nums[ii];
            else nums[i] = nums[ii] + nums[ii + 1];
            max = nums[i] > max ? nums[i] : max;

#ifdef DEBUG
            cout << nums[i];
            if (i < n) cout << ", ";
#endif // DEBUG
        }
        cout << endl;

        return max;
    }
};

int main(int argc, char* argv[]) {
    int n = 0;
    if (argc == 2) n = stoi(argv[1]);
    else {
        cout << "please input n: ";
        cin >> n;
    }

    Solution solution;
    cout << solution.getMaximumGenerated(n) << endl;

    return 0;
}