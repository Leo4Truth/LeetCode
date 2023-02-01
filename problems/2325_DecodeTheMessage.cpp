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
    virtual string decodeMessage(string key, string message)  = 0;
};

class Solution_init : public Solution {
public:
    string decodeMessage(string key, string message)  {
        unordered_map<char, char> map;
        char subc = 'a';
        for (char c : key) {
            if (c != ' ' && map.count(c) == 0) {
                map.emplace(c, subc++);
                // cout << c << ": " << (subc - 1) << endl;
            }
        }
        // cout << endl;
        string decoded = "";
        for (char c : message) {
            if (c == ' ') decoded.push_back(' ');
            else decoded.push_back(map[c]);
        }
        return decoded;
    }

private:
};

int main(int argc, char* argv[]) {
    string key = argc >= 2 ? argv[1] : "";
    string message = argc >= 3 ? argv[2] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->decodeMessage(key, message) << endl;

    return 0;
}
