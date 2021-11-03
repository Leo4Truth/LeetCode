#include <iostream>
#include <math.h>

using namespace std;

class Solution29 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;

		long dvd = labs(dividend), dvs = labs(divisor), res = 0;
		int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

		while (dvd >= dvs) {
			long temp = dvs, m = 1;
			while (temp << 1 <= dvd) {
				temp <<= 1;
				m <<= 1;
			}
			dvd -= temp;
			res += m;
		}

		return sign * res;
	}
};

int main29() {
	int dividend, divisor;
	cin >> dividend >> divisor;
	Solution29 solution;
	cout << solution.divide(dividend, divisor) << endl;
	system("pause");
	return 0;
}