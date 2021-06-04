#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution524 {
public:
    string findLongestWord(string s, vector<string>& d) {

        return "";
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "abpcplea";
    int n = argc >= 3 ? stoi(argv[2]) : 4;
    vector<string> d;
    for (int i = 0; i < n; i++) {
        string dd;
        cin >> dd;
        d.push_back(dd);
    }

    Solution524 solution;
    cout << solution.findLongestWord(s, d) << endl;

    //system("pause");
    return 0;
}

