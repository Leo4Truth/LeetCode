#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for (auto& item : items) {
            if (item[map[ruleKey]].compare(ruleValue) == 0) cnt++;
        }
        return cnt;
    }

private:
    unordered_map<string, int> map = {
        {"tyep", 0}, {"color", 1}, {"name", 2}
    };
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string ruleKey =  argc >= 3 ? argv[2] : "";
    string ruleValue =  argc >= 4 ? argv[3] : "";
    vector<vector<string>> items;
    for (int i = 0; i < n; i++) {
        vector<string> item;
        string type = "";
        string color = "";
        string name = "";
        cin >> type >> color >> name;
        item.push_back(type);
        item.push_back(color);
        item.push_back(name);
        items.push_back(item);
    }

    Solution solution;
    cout << solution.countMatches(items, ruleKey, ruleValue) << endl;
    
    return 0;
}
