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

#define DEBUG

using namespace std;

class Solution {
public:
    virtual int prefixCount(vector<string>& words, string pref) = 0;
};

class Solution_init : public Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string word : words) {
            if (containsPrefix(word, pref)) {
                count++;
            }
        }
        return count;
    }

private:
    bool containsPrefix(string word, string pref) {
        int len = word.length();
        int n = pref.length();
        if (len < n) return false;
        for (int i = 0; i < n; i++) {
            if (word[i] != pref[i]) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string pref = argc >= 3 ? argv[2] : "";
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->prefixCount(words, pref) << endl;

    return 0;
}
