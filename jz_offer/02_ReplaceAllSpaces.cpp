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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        string res = "";
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') res.append("%20");
            else res.append(s.substr(i, 1));
            cout << res << endl;
            i++;
        }
        return res; 
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace_local(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                s[i] = '%';
                s.insert(i + 1, "20");
                i += 3;
            }
            else i++;
            cout << s << endl;
        }
        return s; 
    }
};

int main(int argc, char* argv[]) {
    string s = "We Are Happy";

    Solution solution;
    cout << solution.replaceSpace_local(s) << endl;

    //system("pause");
    return 0;
}

