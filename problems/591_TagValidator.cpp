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
    virtual bool isValid(string code) = 0;
};

class Solution_init : public Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;

        int i = 0;
        while (i < n) {
            if (code[i] == '<') {
                if (i == n - 1) {
                    return false;
                }
                if (code[i + 1] == '/') {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 2, j - (i + 2));
                    if (tags.empty() || tags.top() != tagname) {
                        return false;
                    }
                    tags.pop();
                    i = j + 1;
                    if (tags.empty() && i != n) {
                        return false;
                    }
                }
                else if (code[i + 1] == '!') {
                    if (tags.empty()) {
                        return false;
                    }
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    i = j + 1;
                }
                else {
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 1, j - (i + 1));
                    if (tagname.size() < 1 || tagname.size() > 9) {
                        return false;
                    }
                    if (!all_of(tagname.begin(), tagname.end(), [](unsigned char c) { return isupper(c); })) {
                        return false;
                    }
                    tags.push(move(tagname));
                    i = j + 1;
                }
            }
            else {
                if (tags.empty()) {
                    return false;
                }
                ++i;
            }
        }

        return tags.empty();
    }

private:
};

int main(int argc, char* argv[]) {
    string code = argc >= 2 ? argv[1] : "";
    code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->isValid(code) << endl;

    return 0;
}
