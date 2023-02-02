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
    virtual bool isAlienSorted(vector<string>& words, string order) = 0;
};

class Solution_init : public Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < 26; i++) map[order[i]] = i;
        for (int i = 1; i < words.size(); i++) {
            if (compare(words[i - 1], words[i], map) > 0) return false;
        }
        return true;
    }

private:
    int compare(string word1, string word2, unordered_map<char, int>& map) {
        int n1 = word1.size();
        int n2 = word2.size();
        for (int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
            if (map[word1[i]] < map[word2[j]]) return -1;
            else if (map[word1[i]] > map[word2[j]]) return 1;
        }
        if (n1 == n2) return 0;
        return n1 < n2 ? -1 : 1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string order = argc >= 3 ? argv[2] : "abcdefghijklmnopqrstuvwxyz";
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->isAlienSorted(words, order) << endl;

    return 0;
}
