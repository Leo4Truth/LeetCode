#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min(s.size(), t.size()); i++) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
                if (s.size() < t.size()) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
            }
        }
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "ab";
    string t = argc >= 3 ? argv[1] : "acb";

    Solution solution;
    cout << solution.isOneEditDistance(s, t) << endl;

    //system("pause");
    return 0;
}
