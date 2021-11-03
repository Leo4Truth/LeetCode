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
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = split(version1);
        vector<int> vec2 = split(version2);
        int n1 = vec1.size();
        int n2 = vec2.size();
        int i = 0;
        while (i < n1 && i < n2) {
            if (vec1[i] < vec2[i]) return -1;
            else if (vec1[i] > vec2[i]) return 1;
            i++;
        }
        while (i < n1) {
            if (vec1[i++] > 0) return 1;
        }
        while (i < n2) {
            if (vec2[i++] > 0) return -1;
        }
        return 0;
    }

    vector<int> split(string version) {
        int n = version.size();
        vector<int> vec;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (version[i] == '.') {
                int x = stoi(version.substr(s, i - s));
                vec.push_back(x);
                s = i + 1;
            }
        }
        if (n > s) {
            int x = stoi(version.substr(s, n - s));
            vec.push_back(x);
        }
        return vec;
    }
};

int main(int argc, char* argv[]) {
    string version1 = argc >= 2 ? argv[1] : "";
    string version2 = argc >= 3 ? argv[2] : "";

    Solution solution;
    cout << solution.compareVersion(version1, version2) << endl;

    //system("pause");
    return 0;
}
