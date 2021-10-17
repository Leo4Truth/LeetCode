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
    bool areNumbersAscending(string s) {
        int len = s.size();
        if (len == 0) return true;
        vector<int> num_tokens;
        int prev_num = INT32_MIN;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                string num_str;
                int start = i;
                while (s[i] >= '0' && s[i] <= '9') i++;
                num_str = s.substr(start, i - start);
                int num = stoi(num_str);
                if (cnt == 0) {
                    prev_num = num;
                    cnt++;
                } else {
                    if (num > prev_num) {
                        prev_num = num;
                        cnt++;
                    } else return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.areNumbersAscending(s) << endl;
    
    return 0;
}
