#include <iostream>
#include <vector>

using namespace std;

class Solution573 {
public:
    int distance(vector<int>& a, vector<int>& b) { return abs(a[0] - b[0]) + abs(a[1] - b[1]); }

    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size();
        int max = INT32_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int ds = distance(nuts[i], squirrel);
            int dt = distance(nuts[i], tree);
            sum += dt * 2;
            if (dt - ds > max) max = dt - ds;
        }
        sum = sum - max;
        return sum;
    }
};

int main(int argc, char* argv[]) {
    int h = argc >= 2 ? stoi(argv[1]) : 5;
    int w = argc >= 3 ? stoi(argv[2]) : 7;
    vector<int> tree{2, 2};
    vector<int> squirrel{4, 4};
    if (argc >= 3) {
        cin >> tree[0] >> tree[1];
        cin >> squirrel[0] >> squirrel[1];
    }

    vector<vector<int>> nuts;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nuts.push_back(vector<int>{x, y});
    }

    Solution573 solution;
    cout << solution.minDistance(h, w, tree, squirrel, nuts) << endl;

    //system("pause");
    return 0;
}
