#include <iostream>
#include <vector>

using namespace std;

class Solution139 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
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
