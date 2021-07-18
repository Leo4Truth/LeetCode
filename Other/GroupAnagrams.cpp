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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return {};
        unordered_map<string, vector<string>> map;
        for (auto s : strs) {
            vector<int> count(26, 0);
            int len = s.length();
            for (int i = 0; i < len; i++) count[(int)(s[i] - 'a')]++;
            string ss = "";
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) ss.insert(ss.end(), count[i], (char)(i + 'a'));
            }
            if (!map.count(ss)) map[ss] = vector<string>();
            map[ss].push_back(s);
        }
        vector<vector<string>> res;
        for (auto entry : map) res.push_back(entry.second);
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    Solution solution;
    vector<vector<string>> res = solution.groupAnagrams(strs);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "\t[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << "\"" << res[i][j] << "\"";
            if (j != res[i].size() - 1) cout << ", ";
        }
        if (i != res.size() - 1) cout << "]," << endl;
        else cout << "]" << endl;
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
