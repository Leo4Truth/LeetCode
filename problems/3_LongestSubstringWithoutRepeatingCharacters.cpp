#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Sliding Window, Set
    int lengthOfLongestSubstring_set(string s) {
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

	// Sliding Window, Map
	int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        unordered_map<char, int> map;
        int l = 0, r = 0;
        int max = 0;
        while (l < n && r < n) {
            if (!map.count(s[r]) || map[s[r]] == 0) {
                map[s[r++]] = 1;
                max = r - l > max ? r - l : max;
            }
            else map[s[l++]] = 0;
        }
        return max;
    }

	// Sliding Window
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;

		int maxLen = 1;
		int start = 0, end = 0;

		while (end < s.length()) {
			bool repeat = false;
			for (int i = start; i <= end; i++) {

				// Debug
				//for (int j = start; j <= end; j++) cout << s[j];
				//cout << endl;

				if (s[i] == s[end + 1]) {
					repeat = true;
					//cout << "repeat, ";
					maxLen = end - start + 1 > maxLen ? end - start + 1 : maxLen;
					//cout << "MaxLen = " << maxLen << endl;
					start = i + 1;
					break;
				}
			}

			if (!repeat) end++;
			if (end == s.length() - 1) {
				maxLen = end - start + 1 > maxLen ? end - start + 1 : maxLen;
				break;
			}
		}

		return maxLen;
	}
};

int main() {
	Solution solution;
	string s;
	cin >> s;
	cout << solution.lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}