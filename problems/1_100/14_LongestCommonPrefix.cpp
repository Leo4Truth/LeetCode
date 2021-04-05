#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution14 {
public:
	// Simple Method
	// ���ȡǰ׺
	// Repeat use longestCommonPrefixForTwoStrs until one of the following conditions happens
	//   1. there is only one string in the strs
	//   2. the intermediate result (lcp) is empty string
	string longestCommonPrefix1(vector<string>& strs) {
		if (strs.empty()) return "";
		while (strs.size() != 1) {
			string lcp = longestCommonPrefixForTwoStrs(strs[0], strs[1]);
			if (lcp.empty()) return lcp;
			strs.erase(strs.begin());
			strs.erase(strs.begin());
			strs.push_back(lcp);
		}
		return strs[0];
	}

	// Another simple method
	// ˮƽɨ�跨
	// Compare the character at the same location of all strings in the array
	string longestCommonPrefix2(vector<string>& strs) {
		if (strs.empty()) return "";

	}

	// Longest Common Prefix For Two Strings
	string longestCommonPrefixForTwoStrs(string &str1, string &str2) {
		string s = "";
		for (int i = 0; ; i++) {
			if (str1.empty() || str2.empty()) return "";
			if (i > str1.length() - 1 || i > str2.length() - 1) break;
			if (str1.at(i) == str2.at(i)) s += str1.at(i);
			else break;
		}
		return s;
	}
};

int main14()
{
	vector<string> strs = {
		"abc",
		"abcd",
		"abcde",
		"abcdef"
	};

	Solution14 solution;
	cout << solution.longestCommonPrefix1(strs) << endl;
	system("pause");

	return 0;
}