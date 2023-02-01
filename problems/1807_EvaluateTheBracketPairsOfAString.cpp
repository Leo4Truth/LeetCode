#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual string evaluate(string s, vector<vector<string>>& knowledge) = 0;
};

class Solution_hashmap : public Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto &kd : knowledge) {
            dict[kd[0]] = kd[1];
        }
        bool addKey = false;
        string key, res;
        for (char c : s) {
            if (c == '(') {
                addKey = true;
            } else if (c == ')') {
                if (dict.count(key) > 0) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            } else {
                if (addKey) {
                    key.push_back(c);
                } else {
                    res.push_back(c);
                }
            }
        }
        return res;
    }

private:
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<string>> knowledge;
    for (int i = 0; i < n; i++) {
        string key;
        string value;
        cin >> key >> value;
        knowledge.push_back({key, value});
    }

    Solution *solution = nullptr;

    solution = new Solution_hashmap();
    cout << solution->evaluate(s, knowledge) << endl;

    return 0;
}
