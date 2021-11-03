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
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        if (n == 2) return 1;

        unordered_map<int, int> 
        for (int remove = 0; remove < n; remove++) {
            vector<int> roots;
            for (int i = 0; i < n; i++) {
                if (parents[i] == remove || (parents[i] == -1 && remove != i)) {
                    roots.push_back(i);
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> parents;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        parents.push_back(parent);
    }

    Solution solution;
    cout << solution.countHighestScoreNodes(parents) << endl;
    
    return 0;
}
