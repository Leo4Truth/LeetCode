#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1249 {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        unordered_set<int> indices2reomove;
        deque<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push_back(i);
            }
            else if (s[i] == ')') {
                if (stk.empty()) indices2reomove.insert(i);
                else stk.pop_back();
            }
        }
        while (!stk.empty()) {
            indices2reomove.insert(stk.back());
            stk.pop_back();
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (indices2reomove.find(i) == indices2reomove.end()) res += s[i];
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "a)b(c)d";

    Solution1249 solution;
    cout << solution.minRemoveToMakeValid(s) << endl;

    //system("pause");
    return 0;
}

