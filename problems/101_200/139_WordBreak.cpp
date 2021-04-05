#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (visited[start]) continue;
            for (int end = start + 1; end <= s.length(); end++) {
                if (wordSet.find(s.substr(start, end - start)) != wordSet.end()) {
                    q.push(end);
                    if (end == s.length()) {
                        return true;
                    }
                }
            }
            visited[start] = true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";
    int n = argc >= 3 ? stoi(argv[2]) : 3;
    vector<string> wordDict;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        wordDict.push_back(word);
    }

    Solution139 solution;
    cout << solution.wordBreak(s, wordDict) << endl;

    //system("pause");
    return 0;
}
