#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution1048 {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){ return a.size() < b.size(); });
        int n = words.size();
        int m = words.back().size(); // max-length of word in words
        vector<int> dp(n, 1);

        unordered_set<string> hashSet;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int len = word.size();
        }

        int res = 0;
        return res; 
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution1048 solution;
    cout << solution.longestStrChain(words) << endl;

    //system("pause");
    return 0;
}
