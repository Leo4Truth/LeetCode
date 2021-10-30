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
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        if (n < k) return "";

        unordered_map<string, int> count;
        for (auto str : arr) count[str]++;

        int kk = 0;
        for (int i = 0; i < n; i++) {
            if (count.count(arr[i]) == 1 && count[arr[i]] == 1) {
                kk++;
                if (kk == k) return arr[i];
            }
        }

        return "";
    }
};

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
