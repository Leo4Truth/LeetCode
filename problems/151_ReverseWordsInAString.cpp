#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution151 {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> words;
        int start = 0;
        while (s[start] == ' ') start++;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && i > start) {
                string word = s.substr(start, i - start);
                words.push(word);
                start = i + 1;
                while (s[start] == ' ') start++;
            }
        }
        while (s[start] == ' ' && start < n) start++;
        if (start != n) words.push(s.substr(start, n - start + 1));
        string res = "";
        while (!words.empty()) {
            res.append(words.top());
            words.pop();
            if (!words.empty()) res.append(" ");
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "the sky is blue";

    Solution151 solution;
    cout << solution.reverseWords(s) << endl;

    //system("pause");
    return 0;
}

