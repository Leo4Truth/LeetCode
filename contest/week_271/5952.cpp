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
    virtual int countPoints(string rings) = 0;
};

class Solution_init : public Solution {
public:
    int countPoints(string rings) {
        int n = rings.size() / 2;
        if (n == 0) return 0;

        unordered_map<int, unordered_set<char>> map;
        for (int j = 0; j < n * 2; j += 2) {
            char color = rings[j];
            int i = stoi(rings.substr(j + 1, 1));
            map[i].insert(color);
        }

        int cnt = 0;
        for (auto entry : map) {
            if (entry.second.size() == 3) cnt++;
        }
        
        return cnt;
    }

private:
};

int main(int argc, char* argv[]) {
    string rings = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->countPoints(rings) << endl;

    return 0;
}
