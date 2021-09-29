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
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if (n == 1) return rotateArray[0];
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (rotateArray[i] > rotateArray[next]) return rotateArray[next];
        }
        return rotateArray[0];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> rotateArray;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rotateArray.push_back(x);
    }

    Solution solution;
    cout << solution.minNumberInRotateArray(rotateArray) << endl;

    //system("pause");
    return 0;
}

