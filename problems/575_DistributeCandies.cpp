#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution575 {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> types;
        for (int i = 0; i < n; i++) types.insert(candyType[i]);
        int eatCnt = n / 2;
        if (eatCnt < types.size()) return eatCnt;
        else return types.size();
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> candyType;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        candyType.push_back(x);
    }

    Solution575 solution;
    cout << solution.distributeCandies(candyType) << endl;

    //system("pause");
    return 0;
}

