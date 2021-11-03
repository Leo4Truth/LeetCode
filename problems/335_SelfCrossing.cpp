#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual bool isSelfCrossing(vector<int>& distance) = 0;
};

class Solution_init : public Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        for (int i = 3; i < n; ++i) {
            // 第 1 类路径交叉的情况
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }

            // 第 2 类路径交叉的情况
            if (i == 4 && (distance[3] == distance[1]
                && distance[4] >= distance[2] - distance[0])) {
                return true;
            }

            // 第 3 类路径交叉的情况
            if (i >= 5 && (distance[i - 3] - distance[i - 5] <= distance[i - 1]
                && distance[i - 1] <= distance[i - 3]
                && distance[i] >= distance[i - 2] - distance[i - 4]
                && distance[i - 2] > distance[i - 4])) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> distance;
    for (int i = 0; i < n; i++) {
        int dis;
        cin >> dis;
        distance.push_back(dis);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->isSelfCrossing(distance) << endl;
    
    return 0;
}
