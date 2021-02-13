#include <iostream>
#include <vector>

using namespace std;

class Solution71 {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        int start = 0;
        for (; start < path.size() && path[start] == '/'; start++);
        
        int i = 0;
        for (i = start + 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (start != i) {
                    dir = path.substr(start, i - start);
                    dirs.push_back(dir);
                    for (start = i + 1; start < path.size() && path[start] == '/'; start++);
                    i = start;
                }
            }
        }
        if (start < path.size()) {
            dir = path.substr(start, i - start);
            dirs.push_back(dir);
        }

        for (i = 0; i < dirs.size(); i++) {
            if (dirs[i].size() == 1 && dirs[i][0] == '.') {
                dirs.erase(dirs.begin() + i);
                i--;
            }
            else if (dirs[i].size() == 2 && dirs[i][0] == '.' && dirs[i][1] == '.') {
                dirs.erase(dirs.begin() + i);
                if (i >= 1) {
                    dirs.erase(dirs.begin() + i - 1);
                    i -= 2;
                }
                else i--;
            }
        }

        string res;
        for (i = 0; i < dirs.size(); i++) {
            cout << dirs[i] << endl;
            res.append("/" + dirs[i]);
        }

        if (res.empty()) res.append("/");

        return res;
    }
};

int main71() {
    Solution71 solution;
    string path;
    cin >> path;
    cout << solution.simplifyPath(path) << endl;
    system("pause");
    return 0;
}