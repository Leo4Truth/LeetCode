#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> count(10000, 0);
        for (auto t : deck) count[t]++;
        
        int g = -1;
        for (int i = 0; i < 10000; i++) {
            if (count[i] > 0) {
                if (g == -1) g = count[i];
                else g = gcd(g, count[i]);
            }
        }

        return g > 1;
    }

private:
    inline int gcd(int a, int b) {
        int r;
        while (b > 0) {
            r =a % b;
            a = b;
            b = r;
        }
        return a;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> deck;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        deck.push_back(t);
    }

    Solution solution;
    cout << solution.hasGroupsSizeX(deck) << endl;

    return 0;
}
