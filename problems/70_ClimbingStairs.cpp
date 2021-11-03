#include <iostream>
#include <vector>

using namespace std;

class Solution70 {
public:
	int climbStairs(int n) {
		vector<int> steps;
		steps.push_back(1);
		steps.push_back(2);
		for (int i = 2; i < n; i++) {
			steps.push_back(steps.at(i - 2) + steps.at(i - 1));
		}
		return steps.at(n - 1);
	}
};

int main70() {
	return 0;
}