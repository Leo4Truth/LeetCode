#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution67 {
public:
	string addBinary(string a, string b) {
		int ia, ib;
		string sum;
		//vector<int> sumVec;
		int carry = 0;
		for (ia = a.size() - 1, ib = b.size() - 1; ia >= 0 && ib >= 0; ia--, ib--) {
			if (a.at(ia) == '1' && b.at(ib) == '1' && carry == 1) {
				carry = 1;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else if (a.at(ia) == '0' && b.at(ib) == '1' && carry == 1 ||
				a.at(ia) == '1' && b.at(ib) == '0' && carry == 1 || 
				a.at(ia) == '1' && b.at(ib) == '1' && carry == 0) {
				carry = 1;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
			else if (a.at(ia) == '0' && b.at(ib) == '0' && carry == 1 ||
				a.at(ia) == '0' && b.at(ib) == '1' && carry == 0 ||
				a.at(ia) == '1' && b.at(ib) == '0' && carry == 0) {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
		}

		for (; ia >= 0; ia--) {
			if (a.at(ia) == '1' && carry == 1) {
				carry = 1;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
			else if (a.at(ia) == '1' && carry == 0) {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else if (a.at(ia) == '0' && carry == 1) {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
		}

		for (; ib >= 0; ib--) {
			if (b.at(ib) == '1' && carry == 1) {
				carry = 1;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
			else if (b.at(ib) == '1' && carry == 0) {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else if (b.at(ib) == '0' && carry == 1) {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 1);
				sum.insert(sum.begin(), '1');
			}
			else {
				carry = 0;
				//sumVec.insert(sumVec.begin(), 0);
				sum.insert(sum.begin(), '0');
			}
		}

		if (carry == 1) //sumVec.insert(sumVec.begin(), 1);
			sum.insert(sum.begin(), '1');

		//for (int i = 0; i < sumVec.size(); i++) sum += '0' + sumVec.at(i);

		return sum;
	}
};

int main67() {
	Solution67 solution67;
	string a, b;
	cin >> a >> b;
	cout << solution67.addBinary(a, b) << endl;
	system("pause");
	return 0;
}