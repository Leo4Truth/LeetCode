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
    // TODO
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        for (int i = 0; i < n; i++) {
            int p = i;
            if (nums[p] == 0) continue;
            int flag = nums[p] > 0 ? 1 : -1;
            int k = 1;
            unordered_set<int> seq;
            while (nums[p] * flag > 0) {
                seq.insert(p);
                p = ((p + nums[p]) % n + n) % n;
                if (seq.count(p) > 0) {
                    if (seq.size() > 1) return true; // loop
                    else break;
                }
            }
        }
        return false;
    }

    // Quick & Slow Pointers
    bool circularArrayLoop_official(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n; // 保证返回值在 [0,n) 中
        };

        for (int i = 0; i < n; i++) {
            if (!nums[i]) {
                continue;
            }
            int slow = i, fast = next(i);
            // 判断非零且方向相同
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            int add = i;
            while (nums[add] * nums[next(add)] > 0) {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;
    cout << solution.circularArrayLoop(nums) << endl;

    //system("pause");
    return 0;
}
