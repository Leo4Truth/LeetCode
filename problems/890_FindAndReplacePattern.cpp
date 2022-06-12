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
    virtual vector<string> findAndReplacePattern(vector<string>& words, string pattern) = 0;
};

class Solution_map : public Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        if (n == 0) return {};
        vector<string> res;
        for (string word : words) {
            bool flag = true;
            unordered_map<char, char> map;
            unordered_map<char, char> rmap;
            for (int i = 0; i < word.length(); i++) {
                if (map.count(pattern[i]) == 0 && rmap.count(word[i]) == 0) {
                    map[pattern[i]] = word[i];
                    rmap[word[i]] = pattern[i];
                } else {
                    if (word[i] != map[pattern[i]] || pattern[i] != rmap[word[i]]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string pattern = argc >= 3 ? argv[2] : "";
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution *solution = nullptr;

    solution = new Solution_map();
    vector<string> res = solution->findAndReplacePattern(words, pattern);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "\"" << res[i] << "\"";
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
