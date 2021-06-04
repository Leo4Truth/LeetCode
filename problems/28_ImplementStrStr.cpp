#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution28 {
public:
    int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int t = haystack.length() - needle.length() + 1;

        for (auto i = 0; i < t; i++) {
			for (auto j = 0; j < needle.length(); j++) {
				if (haystack.at(i + j) != needle.at(j)) break;
				if (j == needle.length() - 1) return i;
			}
        }
		return -1;
    }
};

int main28() {
	Solution28 solution;
	string haystack, needdle;
	cin >> haystack;
	cin >> needdle;
	cout << solution.strStr(haystack, needdle);
	system("pause");
	return 0;
}