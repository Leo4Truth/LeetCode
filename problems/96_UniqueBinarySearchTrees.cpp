#include <iostream>
#include <vector>

using namespace std;

class Solution96 {
public:
    int numTrees(int n) {
		vector<int> nums(n + 1, 0);
		nums[0] = 1;
		nums[1] = 1;
		for (int nn = 2; nn <= n; nn++) {
			int num = 0;
			for (int ln = 0; ln <= nn - 1; ln++) {
				int rn = nn - 1 - ln;
				num += nums[ln] * nums[rn];
			}
			nums[nn] = num;
		}
		return nums[n];
    }
};

int main96() {
	Solution96 solution;
	int n;
	cin >> n;
	cout << solution.numTrees(n) << endl;
	system("pause");
	return 0;
}