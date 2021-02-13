#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int len = s.length();
        int left = 0;
        int max = 0;

        for (int i = 0; i < len; i++) {
            map[s[i]]++;
            while (map.size() > k) {
                if (--map[s[left]] == 0) map.erase(s[left]);
                left++;
            }
            max = i - left + 1 > max ? i - left + 1 : max;
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    string s;
    int k;
    if (argc == 3) {
        s = argv[1];
        k = stoi(argv[2]);
    }
    else {
        cout << "Please input s: " << endl;
        cin >> s;
        cout << "Please input k: " << endl;
        cin >> k;
    }

    Solution solution;

    cout << "Result: " << solution.lengthOfLongestSubstringKDistinct(s, k) << endl;

    return 0;
}