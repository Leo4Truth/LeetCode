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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = houses.size();
        int n = heaters.size();

        int rad = 0;
        for (auto house : houses) {
            auto closest_heater = lower_bound(heaters.begin(), heaters.end(), house);
            int dis = 0;
            if (closest_heater == heaters.end()) dis = house - heaters[n - 1];
            else dis = abs(house - *closest_heater);
            rad = dis > rad ? dis : rad;
        }

        return rad;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> houses;
    vector<int> heaters;
    for (int i = 0; i < m; i++) {
        int house;
        cin >> house;
        houses.push_back(house);
    }
    for (int i = 0; i < n; i++) {
        int heater;
        cin >> heater;
        heaters.push_back(heater);
    }

    Solution solution;
    cout << solution.findRadius(houses, heaters) << endl;

    return 0;
}
