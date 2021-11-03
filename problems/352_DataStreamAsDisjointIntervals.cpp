#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * @brief 
 * 
 * 对于给定的 val , 我们需要找到区间 [l0, r0] , 使得 l0 是最大的满足的 l0 < val 的区间
 * 同时, 我们需要找到区间 [l1, r1] , 使得l1是最小的满足 val < l1 的区间
 * 分 5 种情况:
 * 1. l0 <= val <= r0
 * 2. r0 + 1 == val
 * 3. l1 - 1 == val
 * 4. r0 + 1 == val 并且 l1 - 1 == val
 * 5. 以上情况均不满足
 * 
 */
class SummaryRanges {
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        // 找到 l1 最小的且满足 l1 > val 的区间 interval1 = [l1, r1]
        // 如果不存在这样的区间，interval1 为尾迭代器
        auto interval1 = intervals.upper_bound(val);
        // 找到 l0 最大的且满足 l0 <= val 的区间 interval0 = [l0, r0]
        // 在有序集合中，interval0 就是 interval1 的前一个区间
        // 如果不存在这样的区间，interval0 为尾迭代器
        auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

        if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second) {
            // 情况一
            return;
        }
        else {
            bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
            bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
            if (left_aside && right_aside) {
                // 情况四
                int left = interval0->first, right = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left, right);
            }
            else if (left_aside) {
                // 情况二
                ++interval0->second;
            }
            else if (right_aside) {
                // 情况三
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            }
            else {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals_vec;
        for (auto& entry : intervals) {
            intervals_vec.push_back({entry.first, entry.second});
        }
        return intervals_vec;
    }

private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main(int argc, char* argv[]) {
    SummaryRanges summaryRanges;
    string op;
    cin >> op;
    while (op.compare("exit") != 0) {
        if (op.compare("addNum") == 0) {
            int num;
            cin >> num;
            summaryRanges.addNum(num);
        } else if (op.compare("getIntervals") == 0) {
            vector<vector<int>> intervals_vec = summaryRanges.getIntervals();
            cout << "[" << endl;
            for (auto& interval : intervals_vec) {
                cout << "    [" << interval[0] << "," << interval[1] << "]" << endl;
            }
            cout << "]" << endl;
        }
        cin >> op;
    }

    return 0;
}
