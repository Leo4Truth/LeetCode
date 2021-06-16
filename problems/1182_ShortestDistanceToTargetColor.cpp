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
    // Brute Forcee
    // linear search both sides
    // Time Complexity: O(m*n)
    // Limit Time Exceeded
    vector<int> shortestDistanceColor_bf(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int m = queries.size();
        if (n == 0 || m == 0) return {};
        vector<int> distance;
        for (int i = 0; i < m; i++) {
            int index = queries[i][0];
            int target = queries[i][1];
            if (colors[index] == target) {
                distance.push_back(0);
                continue;
            }
            int l = index - 1;
            while (l >= 0 && colors[l] != target) l--;
            int r = index + 1;
            while (r < n && colors[r] != target) r++;
            if (l < 0 && r < n) distance.push_back(r - index);          // only found at right
            else if (l >= 0 && r >= n) distance.push_back(index - l);   // only found at left
            else if (l < 0 && r >= n) distance.push_back(-1);           // not found both sides
            else distance.push_back((r - index) < (index - l) ? (r - index) : (index - l)); // found both sides
        }
        return distance;
    }

    // Binary Search
    // binary search in target index list
    // Time Complexity:  O(m*log(n))
    // Space Complexity: O(n)
    // Pass
    vector<int> shortestDistanceColor_binary_search(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int m = queries.size();
        if (n == 0 || m == 0) return {};
        vector<int> distance;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            if (!map.count(colors[i])) map[colors[i]] = {i};
            else map[colors[i]].push_back(i);
        }
        for (int i = 0; i < m; i++) {
            int index = queries[i][0];
            int target = queries[i][1];
            // no such color in colors
            if (!map.count(target)) {
                distance.push_back(-1);
                continue;
            }
            // colors[index] == target
            if (colors[index] == target) {
                distance.push_back(0);
                continue;
            }
            // binary search
            int l = 0, r = map[target].size() - 1;
            if (map[target][l] > index) {
                distance.push_back(map[target][l] - index);
                continue;
            }
            if (map[target][r] < index) {
                distance.push_back(index - map[target][r]);
                continue;
            }
            int mid = (l + r) / 2;
            while (l != r - 1) {
                if (map[target][mid] > index) r = mid;
                else l = mid;
                mid = (l + r) / 2;
            }
            int lindex = map[target][l];
            int rindex = map[target][r];
            cout << lindex << ", " << rindex << endl;
            distance.push_back(min(abs(index - lindex), abs(index - rindex)));
        }
        return distance;
    }

    // Precomputed
    // Time Complexity:  O(m + n)
    // Space Complexity: O(n)
    // Pass
    vector<int> shortestDistanceColor_precomputed(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        int m = queries.size();
        if (n == 0 || m == 0) return {};
        vector<int> rightmost = {0, 0, 0};
        vector<int> leftmost = {n - 1, n - 1, n - 1};
        vector<vector<int>> distance(3, vector<int>(n, -1));
        
        // looking forward
        for (int i = 0; i < n; i++) {
            int color = colors[i] - 1;
            for (int j = rightmost[color]; j <= i; j++) {
                distance[color][j] = i - j;
            }
            rightmost[color] = i + 1; // update rightmost index of color
        }
        // looking backward
        for (int i = n - 1; i >= 0; i--) {
            int color = colors[i] - 1;
            for (int j = leftmost[color]; j > i; j--) {
                if (distance[color][j] == -1 || distance[color][j] > j - i) {
                    distance[color][j] = j - i;
                }
            }
            leftmost[color] = i - 1; // update leftmost index of color
        }
        vector<int> queriesRes;
        for (int i = 0; i < m; i++) {
            int index = queries[i][0];
            int target = queries[i][1];
            queriesRes.push_back(distance[target - 1][index]);
        }
        return queriesRes;
    }
};

int main(int argc, char* argv[]) {
    int n;
    int m;
    cin >> n;
    vector<int> colors;
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        colors.push_back(color);
    }
    cin >> m;
    vector<vector<int>> queries;
    for (int i = 0; i < m; i++) {
        int index;
        int target;
        cin >> index >> target;
        queries.push_back({index, target});
    }

    Solution solution;
    vector<int> distance = solution.shortestDistanceColor(colors, queries);
    cout << "[";
    for (int i = 0; i < m; i++) {
        cout << distance[i];
        if (i < m) cout << ",";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
