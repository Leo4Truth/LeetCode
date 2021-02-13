#include <iostream>
#include <vector>

using namespace std;

class Solution80 {
public:
    // two pointers, p2 cnt, p1 set value
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        int current = 0, cnt = 0;
        while (true) {
            while (p2 < nums.size() && nums[p2] == current) {
                p2++;
                if (cnt < 2) cnt++;
            }
            while (cnt > 0) {
                nums[p1++] = current;
                cnt--;
            }
            if (p2 < nums.size()) current = nums[p2];
            else break;
        }
        return p1;
    }
};

int main80() {
    Solution80 solution;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int len = solution.removeDuplicates(nums);
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i < len - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    system("pause");
    return 0;
}