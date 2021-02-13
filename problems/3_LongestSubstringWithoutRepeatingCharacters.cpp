#include <iostream>
#include <string>

using namespace std;

class Solution3 {
public:
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

int main3() {
	Solution3 solution;
	string s;
	cin >> s;
	cout << solution.lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}