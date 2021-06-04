#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return true;

        int current = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (current >= 0) {
                    if (i - current - 1 < k) return false;
                    else current = i;
                }
                else current = i;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 8;
    int k = argc >= 3 ? stoi(argv[2]) : 2;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.kLengthApart(nums, k) << endl;

    //system("pause");
    return 0;
}
