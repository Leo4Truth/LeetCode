#include <iostream>
#include <string>
#include <vector>

//#define DEBUG

using namespace std;

class Solution5 {
public:
	/* 
	// Approach 1, two center move, similar to the expand around center, O(N^2) and O(1), efficient
	string longestPalindrome(string s) {
		if (s.empty()) return "";

		int longestLeftCenter = 0, longestRightCenter = 0, longestLen = 0, longestHalfLen = 0;
		int leftCenter = 0, rightCenter = 0, halfLen = 0;
		
		while (true) {
			halfLen = 0;
			
			for (int left = leftCenter, right = rightCenter; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++, halfLen++);
			
			int start = leftCenter - halfLen + 1;
			int end = rightCenter + halfLen - 1;
			int len = end - start + 1;

			if (len >= longestLen) {
				longestLeftCenter = leftCenter;
				longestRightCenter = rightCenter;
				longestLen = len;
				longestHalfLen = halfLen;
			}

			if (rightCenter == s.size() - 1) break;

			if (leftCenter == rightCenter) rightCenter++;
			else leftCenter++;
		}

		int start = longestLeftCenter - longestHalfLen + 1;
		int end = longestRightCenter + longestHalfLen - 1;
		int len = end - start + 1;

		return s.substr(start, len);
	}
	*/

	// Simple Longest Common Substring doesn't work
	// For example, S = "abacdfgdcaba" and its reverse S' = "abacdgfdcaba" have the common substring "abacd" which is not a palindrome

	/*
	// Approach 2, Dynamic Programming, O(N^2) and O(N^2), not so efficient
	string longestPalindrome(string s) {
		int n = s.length();
		bool **p = new bool*[n];
		for (int i = 0; i < n; i++)
			p[i] = new bool[n];

		int start = 0, end = 0, longestLen = 1;

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				if (i == j) p[i][j] = true;
				else if (i == j - 1) {
					p[i][j] = s[i] == s[j];
					if (p[i][j]) {
						start = i;
						end = j;
						longestLen = 2;
					}
				}
				else p[i][j] = false;
			}

		for (int len = 3; len <= n; len++) {
			for (int i = 0, j = i + len - 1; j < n; i++, j++) {
				if (p[i + 1][j - 1] && s[i] == s[j]) {
					p[i][j] = true;
					if (len >= longestLen) {
						start = i;
						end = j;
						longestLen = len;
					}
				}
			}
		}

		return s.substr(start, longestLen);
	}
	*/

	// Approach 3, Manacher Algorithm, O(N) and O(N), best
 	string longestPalindrome(string s) {
		vector<char> str;
		str.push_back('^');
		str.push_back('#');
		for (int i = 0; i < s.size(); i++) {
			str.push_back(s[i]);
			str.push_back('#');
		}
		str.push_back('$');

		int *p = new int[str.size()];
		p[0] = 0;
		p[str.size() - 1] = 0;
		for (int i = 1; i < str.size() - 1; i++)
			p[i] = 1;

		int maxLen = -1;
		int id = 1, mx = 1; // mx 代表以 id 为中心的最长回文的右边界
		
		for (int i = 1; i < str.size() - 1; i++) {
			p[i] = mx - i ? min(p[2 * id - i], mx - i) : 1; // key code

			while (str[i + p[i]] == str[i - p[i]]) p[i]++;

			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}

		int C = 0, maxP = 0;
		for (int i = 1; i < str.size() - 1; i++)
			if (p[i] > maxP) {
				C = i;
				maxP = p[i];
			}

		return s.substr((C - maxP) / 2, maxP - 1);
	}

	int min(const int& a, const int& b) {
		return a < b ? a : b;
	}
};

int main5() {
	Solution5 solution;
	string s;
	cin >> s;
	while (s[0] != '!') {
		cout << solution.longestPalindrome(s) << endl;
		cin >> s;
	}
	system("pause");
	return 0;
}