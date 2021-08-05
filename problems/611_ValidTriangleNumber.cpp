#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Two Pointers
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) k++;
                count += k - j > 0 ? k - j : 0;
            }
        }
        return count;
    }
    
    // Sort and Binary Search
    int triangleNumber_binarySearch(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int first = 0; first < n - 2; first++) {
            for (int second = first + 1; second < n - 1; second++) {
                int l = second + 1, r = n - 1, k = second;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] < nums[first] + nums[second]) {
                        k = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                count += k - second;
            }
        }
        return count;
    }

    // Simple Solution
    // sort and brute force
    int triangleNumber_bf(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int first = 0, second = 1, third = 2;
        int count = 0;
        while (first < n - 2) {
            second = first + 1;
            while (second < n - 1) {
                third = second + 1;
                while (third < n) {
                    if (nums[first] + nums[second] > nums[third]) {
                        count++;
                        //cout << nums[first] << ", " << nums[second] << ", " << nums[third] << endl;
                    }
                    third++;
                }
                second++;
            }
            first++;
        }
        return count;
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

    Solution solution;
    cout << solution.triangleNumber(nums) << endl;

    //system("pause");
    return 0;
}
