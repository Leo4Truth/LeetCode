#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int trapRainWater(vector<vector<int>>& heightMap) = 0;
};

class Solution_init : public Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        
        return 0;
    }
}

int main(int agrc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> heightMap;
    for (int i = 0; i < m; i++) {
        vector<int> heightRow;
        for (intj = 0; j < n; j++) {
            int height;
            cin >> height;
            heightRow.push_back(height);
        }
        heightMap.push_back(heightRow);
    }

    Solution *solution = new Solution_init();
    cout << solution->trapRainWater(heightMap) << endl;

    return 0;

}
