#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

class Solution89 {
public:
	vector<int> grayCode(int n) {
		int size = pow(2, n);
		vector<int> codes;

		codes.push_back(0);
		if (n == 0) return codes;
		
		codes.push_back(1);
		if (n == 1) return codes;

		for (int i = 2; i <= n; i++) {
			int size = codes.size();
			for (int j = size - 1; j >= 0; j--) {
				codes.push_back(codes.at(j) + size);
			}
		}

		return codes;
	}

	static int bitArray2Int(vector<bool>& bits) {
		int n = bits.size();
		int res = 0;
		for (int i = n - 1; i >= 0; i--)
			if (bits.at(i))
				res += pow(2, n - i - 1);
		return res;
	}
};

int main89() {
	vector<bool> bits;
	for (int i = 0; i < 4; i++) {
		bits.push_back(true);
	}
	cout << Solution89::bitArray2Int(bits) << endl;

	Solution89 solution;
	int n;
	cin >> n;
	vector<int> codes = solution.grayCode(n);
	for (int i = 0; i < pow(2, n); i++) {
		cout << bitset<sizeof(int) * 8>(codes.at(i)) << " - " << codes.at(i) << endl;
	}
	system("pause");

	return 0;
}