#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

int cmp(const pair<char, int>& x, const pair<char, int>& y) {
    return x.second > y.second;
}

class Solution {
public:
    // STL map sorted by value
    // STL map defaultly sorted by key
    string frequencySort(string s) {
        map<char, int, greater<int>> count;
        for (auto ch : s) count[ch]++;

        vector<pair<char, int>> vec;
        for (map<char, int>::iterator it = count.begin(); it != count.end(); it++) {
            vec.push_back(make_pair(it->first, it->second));
        }

        sort(vec.begin(), vec.end(), cmp);

        string sorted_str = "";
        for (auto& p : vec) {
            for (int i = 0; i < p.second; i++) sorted_str.push_back(p.first);
        }

        return sorted_str;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.frequencySort(s) << endl;

    return 0;
}
