#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int s = 0; s < n; s++) {
            if (gas[s] < cost[s]) continue;
            int current = (s + 1) % n;
            int currentGas = gas[s] + gas[(s + 1) % n] - cost[s];
            while (current != s) {
                if (currentGas >= cost[current]) {
                    currentGas -= cost[current];
                    current = (current + 1) % n;
                    currentGas += gas[current];
                }
                else break;
            }
            if (current == s) return s;
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> gas;
    vector<int> cost;
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        gas.push_back(g);
    }
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cost.push_back(c);
    }

    Solution134 solution;
    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}

