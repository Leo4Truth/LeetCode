#include <iostream>
#include <vector>

using namespace std;

class Solution1281 {
public:
	int subtractProductAndSum(int n) {
		if (n == 0) return 0;
		int sum = 0;
		int product = 1;
		while (n > 0) {
			int x = n % 10;
			sum += x;
			product *= x;
			n /= 10;
		}
		return product - sum;
	}
};