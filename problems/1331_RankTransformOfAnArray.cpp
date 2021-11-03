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
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> arr_sorted(arr.begin(), arr.end());
        sort(arr_sorted.begin(), arr_sorted.end());
        vector<int> arr_sorted_rm_dup;
        unordered_map<int, int> hashmap;
        int i = 0;
        while (i < n) {
            int v = arr_sorted[i];
            while (i + 1 < n && arr_sorted[i + 1] == v) i++;
            arr_sorted_rm_dup.push_back(v);
            hashmap[v] = arr_sorted_rm_dup.size();
            i++;
        }
        vector<int> rank;
        for (int i = 0; i < n; i++) rank.push_back(hashmap[arr[i]]);
        return rank;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Solution solution;
    vector<int> rank = solution.arrayRankTransform(arr);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << rank[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
