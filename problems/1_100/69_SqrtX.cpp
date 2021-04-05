#include <iostream>
#include <math.h>

using namespace std;

class Solution69 {
public:
	int mySqrt(int x) {
		if (x < 2) return x;
		int left = (int) exp(0.5*log(x));
		int right = left + 1;
		return (long) right * right > x ? left : right;
	}

	int mySqrt_1(int x) {
		if (x < 2) return x;
		long num;
		int pivot, left = 2, right = x/2;
		while (left < right) {
			pivot = left + (right - left) / 2;
			num = (long) pivot * pivot;
			if (num > x) right = pivot - 1;
			else if (num < x) left = pivot + 1;
			else return pivot;
		}

		return right;
	}
};

int main69(int argc, char* argv[]) {
	int x = argc >= 2 ? stoi(argv[1]) : 8;
	Solution69 solution;
	cout << solution.mySqrt_1(x) << endl;
	return 0;
}