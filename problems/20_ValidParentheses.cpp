#include <iostream>
#include <stack> 
#include <string>
#include <vector>

using namespace std;

class Solution20 {
public:
	bool isValid(string s) {
		stack<char> stk;
		const int length = s.size();
		for (auto i = 0; i < length; i++) {
			if (s.at(i) == '(') stk.push('(');
			else if (s.at(i) == '[') stk.push('[');
			else if (s.at(i) == '{') stk.push('{');
			else if (s.at(i) == ')') {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else return false;
			}
			else if (s.at(i) == ']') {
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else return false;
			}
			else if (s.at(i) == '}') {
				if (!stk.empty() && stk.top() == '{') stk.pop();
				else return false;
			}
		}
		return stk.empty();
	}
};

int main20()
{
	Solution20 solution;
	string s;
	cin >> s;
	if (solution.isValid(s)) cout << "true" << endl;
	else cout << "false" << endl;
	system("pause");
	return 0;
}