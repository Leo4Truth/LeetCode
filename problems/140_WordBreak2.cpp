#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution140 {
public:
    // BFS
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        int n = wordDict.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> answers;
        queue<int> q;
        queue<string> strQ;
        q.push(0);
        strQ.push("");
        while (!q.empty()) {
            int start =  q.front();
            q.pop();
            string currentStr = strQ.front();
            strQ.pop();
            for (int end = start + 1; end <= len; end++) {
                if (wordSet.find(s.substr(start, end - start)) != wordSet.end()) {
                    string newStr = currentStr + s.substr(start, end - start);
                    if (end == len) answers.push_back(newStr);
                    else {
                        q.push(end);
                        strQ.push(newStr + " ");
                    }
                }
            }
        }
        return answers;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "catsanddog";
    int n = argc >= 3 ? stoi(argv[2]) : 5;
    vector<string> wordDict;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        wordDict.push_back(word);
    }


    Solution140 solution;
    vector<string> answers = solution.wordBreak(s, wordDict);

    cout << "[";
    for (int i = 0; i < answers.size(); i++) {
        cout << "\"" << answers[i] << "\"";
        if (i < answers.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
