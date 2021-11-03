#include <iostream>
#include <vector>

using namespace std;

class Solution821 {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        if (n == 0) return {};

        vector<int> res;
        vector<int> cpos;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cpos.push_back(i);
                int m = cpos.size();
                if (m == 1) {
                    for (int j = 0; j <= cpos[0]; j++)
                        res.push_back(cpos[0] - j);
                }
                else if (m > 1) {
                    int d = cpos[m - 1] - cpos[m - 2];
                    for (int j = cpos[m - 2] + 1; j <= cpos[m - 2] + d / 2; j++)
                        res.push_back(j - cpos[m - 2]);
                    for (int j = cpos[m - 2] + d / 2 + 1; j <= cpos[m - 1]; j++)
                        res.push_back(cpos[m - 1] - j);
                }
            }
        }
        for (int j = cpos[cpos.size() - 1] + 1; j < n; j++) {
            res.push_back(j - cpos[cpos.size() - 1]);
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "loveleetcode";
    char c = argc >= 3 ? argv[2][0] : 'e';

    Solution821 solution;
    vector<int> res = solution.shortestToChar(s, c);
    
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    //system("pause");
    return 0;
}
