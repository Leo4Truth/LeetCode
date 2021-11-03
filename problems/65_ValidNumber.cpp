#include <iostream>
#include <vector>

using namespace std;

class Solution65 {
public:
    // a stupid solution.
    bool isNumber_xxx(string s) {
        int signIdx = -1;
        int dotIdx = -1;
        int expIdx = -1;
        int expSignIdx = -1;
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;
        while (end >= 0 && s[end] == ' ') end--;
        if (start > end) return false;
        s = s.substr(start, end - start + 1);

        if (s[0] == 'e') return false;
        if (s.size() == 1 && (s[0] == '.' || s[0] == '+' || s[0] == '-')) return false;

        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                // sign exist
                if (signIdx >= 0) {
                    // exp exist
                    if (expIdx >= 0) {
                        cout << "i: " << i << ", expSignIdx" << endl;
                        expSignIdx = i;
                    }
                    else {
                        cout << "1" << endl;
                        return false;
                    }
                }
                // no sign
                else {
                    if (i == 0) {
                        cout << "i: " << i << ", signIdx" << endl;
                        signIdx = i;
                    }
                    else if (i == expIdx + 1) {
                        cout << "i: " << i << ", expSignIdx" << endl;
                        expSignIdx = i;
                    }
                    else {
                        cout << "2" << endl;
                        return false;
                    }
                }
            }
            else if (s[i] == '.') {
                if (dotIdx >= 0) {
                    cout << "3" << endl;
                    return false;
                }
                else if (expIdx >= 0) {
                    cout << "4" << endl;
                    return false;
                }
                else {
                    cout << "i: " << i << ", dotIdx" << endl;
                    dotIdx = i;
                }
            }
            else if (s[i] == 'e') {
                if (expIdx >= 0) {
                    cout << "5" << endl;
                    return false;
                }
                else {
                    cout << "i: " << i << ", expIdx" << endl;
                    expIdx = i;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                cnt++;
            }
            else {
                cout << "6" << endl;
                return false;
            }
        }

        if (cnt == 0) return false;

        cout << "signIdx:    " << signIdx << endl;
        cout << "dotIdx:     " << dotIdx << endl;
        cout << "expIdx:     " << expIdx << endl;
        cout << "expSignIdx: " << expSignIdx << endl;

        if (expIdx >= 0) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < expIdx; i++) {
                if (s[i] >= '0' && s[i] <= '9') cnt1++;
            }
            for (int i = expIdx + 1; i < s.size(); i++) {
                if (s[i] >= '0' && s[i] <= '9') cnt2++;
            }
            if (cnt1 == 0 || cnt2 == 0) return false;
        }

        vector<int> indices;
        if (signIdx >= 0) indices.push_back(signIdx);
        if (dotIdx >= 0) indices.push_back(dotIdx);
        if (expIdx >= 0) indices.push_back(expIdx);
        if (expSignIdx >= 0) indices.push_back(expSignIdx);

        for (int i = 1; i < indices.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (indices[i] < indices[j]) return false;
            }
        }

        return true;
    }

    bool isNumber(string s) {
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;
        while (end >= 0 && s[end] == ' ') end--;
        if (start > end) return false;
        s = s.substr(start, end - start + 1);
        int expIdx = s.find('e');
        if (expIdx < 0) return isFloat(s, true);
        else return isFloat(s.substr(0, expIdx), true) && isInt(s.substr(expIdx + 1), true);
    }

    bool isInt(string s, bool canHaveSign) {
        int n = s.size();
        if (n == 0) return false;
        int i = 0;
        if (s[0] == '+' || s[0] == '-') {
            if (canHaveSign) i++;
            else return false;
        }
        if (i == s.size()) return false;
        /*
        if (s[i] == '0' && s.size() != 1) return false;
        else i++;
        */
        for (; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }

    bool isFloat(string s, bool canHaveSign) {
        int dotIdx = s.find('.');
        if (dotIdx < 0) return isInt(s, canHaveSign);
        else if (dotIdx == 0) return isInt(s.substr(1), false);
        else if (dotIdx == 1 && (s[0] == '+' || s[0] == '-')) return canHaveSign && isInt(s.substr(2), false);
        else if (dotIdx == s.size() - 1) return isInt(s.substr(0, dotIdx), canHaveSign);
        else return isInt(s.substr(0, dotIdx), canHaveSign) && isInt(s.substr(dotIdx + 1), false);
    }
};

int main65() {
    Solution65 solution;
    string s;
    cin >> s;
    cout << solution.isNumber(s) << endl;
    system("pause");
    return 0;
}