#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for (int i = 1; i < n; i++) {
            int x = 1;
            while (x < k - (n - i) * 26) x++;
            res += (char)('a' - 1 + x);
            k -= x;
        }
        res += (char)('a' - 1 + k);
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 3;
    int k = argc >= 3 ? stoi(argv[2]) : 27;

    Solution solution;
    cout << solution.getSmallestString(n, k) << endl;

    //system("pause");
    return 0;
}
