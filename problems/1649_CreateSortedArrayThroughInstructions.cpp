#include <iostream>
#include <string>
#include <vector>

#define DEBUG

using namespace std;

class Solution {
public:
    int min(const int& a, const int& b) {
        return a < b ? a : b;
    }

    // Binary Search and insert
    // Time Limit Exceeded
    // search with O(logN) time, but the insert with O(N) time
    int createSortedArray_1(vector<int>& instructions) {
        int n = instructions.size();
        if (n == 0) return 0;

        vector<int> nums;
        nums.push_back(instructions[0]);

        int res = 0;

        for (int i = 1; i < n; i++) {
            int x = instructions[i];
            int l = 0, r = nums.size() - 1;
            int mid = (l + r) / 2;
            while (l < r) {
                if (x < nums[mid]) r = mid - 1;
                else if (x > nums[mid]) l = mid + 1;
                else break;
                mid = (l + r) / 2;
            }

            int insert_pos = mid;

#ifdef DEBUG
            print(nums);
            cout << "insert " << x << endl;
#endif // DEBUG
            if (nums[insert_pos] == x) {
                int first = insert_pos, last = insert_pos;
                while (first >= 0 && nums[first] == x) first--;
                while (last < nums.size() && nums[last] == x) last++;
                if (first < 0 || nums[first] != x) first++;
                if (last == nums.size() || nums[last] != x) last--;

#ifdef DEBUG
                cout << "first: " << first << ", last: " << last << endl;
#endif // DEBUG

                if (first <= nums.size() - last - 1) insert_pos = first;
                else insert_pos = last + 1;
            }
            else if (nums[insert_pos] < x) insert_pos++;

#ifdef DEBUG
            cout << "insert pos: " << insert_pos << endl;
#endif // DEBUG

            int cost = min(insert_pos, nums.size() - insert_pos);
            res += cost;
            nums.insert(nums.begin() + insert_pos, x);

#ifdef DEBUG
            cout << "cost: " << cost << endl;
            int insert_pos_first = 0, insert_pos_last = nums.size() - 1;
            while (nums[insert_pos_first] != x) insert_pos_first++;
            while (nums[insert_pos_last] != x) insert_pos_last--;
            int true_cost = min(insert_pos_first, nums.size() - 1 - insert_pos_last);
            cout << "true cost: " << true_cost << endl;
            cout << x << ", " << cost << ", " << true_cost << endl;
            cout << endl;
#endif // DEBUG

        }

        return res;
    }

    void print(vector<int>& nums) {
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            cout << i;
            if (i < nums.size() - 1) cout << ",";
        }
        cout << "]" << endl;
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }

    int createSortedArray_1(vector<int>& instructions) {

    }
};

int main(int argc, char* argv[]) {
    int n;
    vector<int> instructions;

    cout << "please input length of instructions: ";
    cin >> n;
    cout << "please input " << n << " instructions: " <<endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        instructions.push_back(x);
    }

    Solution solution;
    cout << solution.createSortedArray(instructions) << endl;

    return 0;
}