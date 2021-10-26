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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n2; i++) index[nums2[i]] = i;
        vector<int> nextGreater(n1, -1);
        for (int i = 0; i < n1; i++) {
            for (int j = index[nums1[i]] + 1; j < n2; j++) {
                if (nums2[j] > nums1[i]) {
                    nextGreater[i] = nums2[j];
                    break;
                }
            }
        }
        return nextGreater;
    }
};

int main(int argc, char* argv[]) {
    int n1 = argc >= 2 ? stoi(argv[1]) : 0;
    int n2 = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums1;
    vector<int> nums2;
    for (int i = 0; i < n1; i++) {
        int num;
        cin >> num;
        nums1.push_back(num);
    }
    for (int i = 0; i < n2; i++) {
        int num;
        cin >> num;
        nums2.push_back(num);
    }

    Solution solution;
    vector<int> nextGreater = solution.nextGreaterElement(nums1, nums2);
    cout << "[";
    for (int i = 0; i < n1; i++) {
        cout << nextGreater[i];
        if (i < n1 - 1) cout << ",";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
