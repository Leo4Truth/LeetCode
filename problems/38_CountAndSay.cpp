#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay_memo(int n) {
		vector<string> memo;
		memo.push_back("");
		memo.push_back("1");
		for (int i = 2; i <= n; i++) {
			string s = memo[i - 1];
			string res =  "";
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
			memo.push_back(res);
		}
		return memo[n];
	}
	
	string countAndSay_rec(int n) {
		if (n <= 0) return "";
		if (n == 1) return "1";
		string s = countAndSay_rec(n - 1);
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

int main(int argc, char* argv[]) {
	int n = argc >= 2 ? stoi(argv[1]) : 1;

	Solution solution;
	cout << solution.countAndSay_memo(n) << endl;

	return 0;
}