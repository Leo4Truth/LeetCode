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
    virtual int game(vector<int>& guess, vector<int>& answer) = 0;
};

class Solution_init : public Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int n = guess.size() <= answer.size() ? guess.size() : answer.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += guess[i] == answer[i];
        return cnt;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();

    return 0;
}
