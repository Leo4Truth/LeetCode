#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution268 {
public:
    int missingNumber_hashSet(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        for (int i = 0; i < n; i++) numSet.insert(nums[i]);
        int expectedNumCnt = nums.size() + 1;
        for (int num = 0; num < expectedNumCnt; num++) {
            if (numSet.find(num) == numSet.end()) return num;
        }
        return -1;
    }

    // index: 0 1 2 3
    // value: 0 1 3 4
    // missing = n ^ (index1^value1) ^ (index2^value2) ^ ... ^ (indexn^valuen)
    //         = 4^(0^0)^(1^1)^(2^3)^(3^4)
    //         = (0^0)^(1^1)^(3^3)^(4^4)^2
    //         = 0^0^0^0^2
    //         = 2
    int missingNumber_bitManipulattion(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) missing ^= i ^ nums[i];
        return missing;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution268 solution;
    cout << solution.missingNumber_bitManipulattion(nums) << endl;

    //system("pause");
    return 0;
}

