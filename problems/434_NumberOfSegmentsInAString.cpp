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
    int countSegments(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            for (; i < s.size() && s[i] == ' '; i++);
            if (i < s.size()) {
                cnt++;
                for (; i < s.size() && s[i] != ' '; i++);
            }
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    string s = "";
    for (int i = 1; i < argc; i++) {
        s.append(argv[i]);
        if (i != argc - 1) s.append(" ");
    }

    Solution solution;
    cout << solution.countSegments(s) << endl;

    /*
    vector<string> segments = solution.countSegments(s);
    cout << "[";
    for (int i = 0; i < segments.size(); i++) {
        cout << "\"" << segments[i] << "\"";
        if (i < segments.size() - 1) cout << ", ";
    }
    cout << endl;
    */

    //system("pause");
    return 0;
}
