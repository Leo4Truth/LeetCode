#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
	int len = s.size();
	// cout << "len: " << len << endl;
	if (len == 0) return true;
	int cntA = 0;
	int currentConsecutiveL = 0;
	for (int i = 0; i < len; i++) {
	    // cout << i << ", " << s[i] << ": ";
	    // cout << "A: " << cntA << ", currentL: " << currentConsecutiveL << endl;
	    if (s[i] == 'P') currentConsecutiveL = 0;
	    else if (s[i] == 'A') {
		currentConsecutiveL = 0;
		cntA++;
		if (cntA > 1) return false;
	    }
	    else if (s[i] == 'L') {
		currentConsecutiveL++;
		if (currentConsecutiveL >= 3) return false;
	    }
	}
	return true;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    Solution solution;
    if (s.size() == 0) cin >> s;
    cout << s << endl;
    bool result = solution.checkRecord(s);
    if (result) cout << "true" << endl;
    else cout << "false" << endl;
    // system("pause");
    return 0;
}
