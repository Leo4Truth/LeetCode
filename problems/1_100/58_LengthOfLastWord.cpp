#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution58 {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;
		int lastSpace, lastNonSpace;
		for (lastNonSpace = s.size() - 1; lastNonSpace >= 0 && s.at(lastNonSpace) == ' '; lastNonSpace--);
		for (lastSpace = lastNonSpace; lastSpace >= 0 && s.at(lastSpace) != ' '; lastSpace--);
		return lastNonSpace - lastSpace;
	}
};

int main58() {
	string s;
	getline(cin, s);
	Solution58 solution;
	cout << solution.lengthOfLastWord(s) << endl;
	system("pause");
	return 0;
}