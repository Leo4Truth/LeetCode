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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        if (n == 0) return {};
        vector<string> rank;
        unordered_map<int, string> rankMap;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < n; i++) q.push(score[i]);
        for (int i = 0; i < n; i++) {
            int s = q.top();
            q.pop();
            if (i == 0) rankMap[s] = "Gold Medal";
            else if (i == 1) rankMap[s] = "Silver Medal";
            else if (i == 2) rankMap[s] = "Bronze Medal";
            else rankMap[s] = to_string(i + 1);
        }
        for (int i = 0; i < n; i++) rank.push_back(rankMap[score[i]]);
        return rank;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> score;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        score.push_back(s);
    }

    Solution solution;
    vector<string> rank = solution.findRelativeRanks(score);
    for (auto& r : rank) {
        cout << r << endl;
    }
    cout << endl;

    //system("pause");
    return 0;
}
