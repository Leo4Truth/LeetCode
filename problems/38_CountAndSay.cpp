#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution38 {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		if (n == 1) return "1";
		string s = countAndSay(n - 1);
		string res = "";
		int cnt = 0;
		for (auto i = 0; i < s.size(); i++) {
			if (i + 1 < s.size() && s.at(i + 1) == s.at(i)) cnt++;
			else if (i + 1 >= s.size()) {
				cnt++;
				res += to_string(cnt) + s.at(i);
			}
			else {
				cnt++;
				res += to_string(cnt) + s.at(i);
				cnt = 0;
			}
		}
		return res;
	}
};

int main38() {
	int x;
	cin >> x;

	Solution38 solution;

	cout << solution.countAndSay(x) << endl;

	system("pause");

	return 0;
}