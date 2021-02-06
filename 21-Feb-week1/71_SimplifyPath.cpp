#include <iostream>
#include <vector>
#include <queue>

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

    string simplifyPath_stk(string path) {
        deque<string> deq;
        int start = 1;
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                string dir = path.substr(start, i - start);
                start = i + 1;
                if (dir == "..") {
                    if (!deq.empty()) deq.pop_back();
                }
                else if (dir == "." || dir == "") continue;
                else deq.push_back(dir);
            }
        }
        
        if (start < path.size()) {
            int i = path.size() - 1;
            string dir = path.substr(start, i - start + 1);
            if (dir == "..") {
                if (!deq.empty()) deq.pop_back();
            }
            else if (dir == ".") ;
            else deq.push_back(dir);
        }

        string res = "/";
        for (auto dir : deq) {
            res.append(dir);
            res.append("/");
        }

        if (res.size() > 1) return res.substr(0, res.size() - 1);
        return res;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution71 solution;
    cout << solution.simplifyPath_stk(s1) << endl;

    //system("pause");
    return 0;
}
