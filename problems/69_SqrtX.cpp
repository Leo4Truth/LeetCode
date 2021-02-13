#include <iostream>
#include <math.h>

using namespace std;

class Solution69 {
public:
	int mySqrt(int x) {
		return sqrt(x);
	}
};

int main69() {
	int x;
	cin >> x;
	Solution69 solution;
	cout << solution.mySqrt(x) << endl;
	system("pause");
	return 0;
}