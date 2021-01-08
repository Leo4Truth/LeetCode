#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int len = s.length();
        unordered_set<char> set;
        int max = 0;

        while (l < len && r < len) {
            if (!set.count(s[r])) {
                set.insert(s[r++]);
                max = r - l > max ? r - l : max;
            }
            else set.erase(s[l++]);
        }

        return max;
    }

    void print(unordered_map<char, int> map) {
        for (auto pair : map) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    string s;
    if (argc == 2) s = argv[1];
    else {
        cout << "please input string s: " << endl;
        cin >> s;
    }

    Solution solution;
    cout << solution.lengthOfLongestSubstring_1(s) << endl;

    return 0;
}