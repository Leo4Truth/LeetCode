#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1675 {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int min = INT32_MAX;
        for (auto num : nums) {
            if (num % 2 == 0) {
                evens.push(num);
                min = num < min ? num : min;
            }
            else {
                evens.push(num * 2);
                min = num * 2 < min ? num * 2 : min;
            }
        }
        int minDev = INT32_MAX;
        while (!evens.empty()) {
            int x = evens.top();
            evens.pop();
            minDev = x - min < minDev ? x - min : minDev;
            if (x % 2 == 0) {
                evens.push(x / 2);
                min = x / 2 < min ? x / 2 : min;
            }
            else break;
        }
        return minDev;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 4;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution1675 solution;
    cout << solution.minimumDeviation(nums) << endl;
    
    //system("pause");
    return 0;
}
