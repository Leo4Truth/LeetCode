#include <iostream>
#include <vector>

using namespace std;

class Solution81 {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, cnt = 0;
        int direct = 0;
        while (cnt < n) {
            if (nums[i] < target) {
                if (direct == -1) return false;
                else direct = 1;
            }
            else if (nums[i] > target) {
                if (direct == 1) return false;
                else direct = -1;
            }
            else return true;

            i = i + direct;
            if (i >= n) i -= n;
            else if (i < 0) i += n;
            cnt++;

            //cout << "i: " << i << ", " << "cnt: " << cnt << endl;
        }
        return false;
    }
};

int main81() {
    Solution81 solution;
    int n, target;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cin >> target;
    cout << solution.search(nums, target) << endl;
    system("pause");
    return 0;
}