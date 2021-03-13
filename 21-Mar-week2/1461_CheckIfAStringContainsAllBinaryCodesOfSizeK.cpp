#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution1461 {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> set;
        for (int i = 0; i <= n - k; i++) {
            string substr = s.substr(i, k);
            set.insert(substr);
        }
        for (auto substr : set) cout << substr << endl;
        cout << set.size() << endl;
        return set.size() == (int)pow(2, k);
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "10";
    int k = argc >= 3 ? stoi(argv[2]) : 1;

    Solution1461 solution;
    cout << solution.hasAllCodes(s, k) << endl;

    //system("pause");
    return 0;
}
