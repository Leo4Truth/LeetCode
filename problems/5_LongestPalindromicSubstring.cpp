#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // expand around center, O(N^2) time, O(1) space
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int max = 1;
        int max_left = 0, max_right = 0;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == s[i + 1]) {
                max = 2;
                max_left = i;
                max_right = i + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int w = 1; i + w < n && i - w >= 0; w++) {
                if (s[i - w] != s[i + w]) break;
                if (w * 2 + 1 > max) {
                    max = w * 2 + 1;
                    max_left = i - w;
                    max_right = i + w;
                }
            }
            if (s[i] == s[i + 1]) {
                for (int w = 1; i + w + 1 < n && i - w >= 0; w++) {
                    if (s[i - w] != s[i + w + 1]) break;
                    if (w * 2 + 2 > max) {
                        max = w * 2 + 2;
                        max_left = i - w;
                        max_right = i + w + 1;
                    }
                }
            }
        }

        return s.substr(max_left, max_right - max_left + 1);
    }

    string Manacher(string s) {
        int n = s.size();
        if (n == 0) return "";
        vector<char> str;
        str.push_back('^');
        str.push_back('#');
        for (int i = 0; i < n; i++) {
            str.push_back(s[i]);
            str.push_back('#');
        }
        str.push_back('$');

        vector<int> p(str.size(), 1);
        p[0] = 0;
        p[str.size() - 1] = 0;

        int max = -1;
        int maxi = -1;
        int id = 1, mx = 1; // mx 代表以 id 为中心的最长回文的右边界

        //         j = id * 2 - i
        //              \/
        // __mx的对称点__j__id__i__mx__
        for (int i = 1; i < str.size(); i++) {
            /*
             * (2 * id - i) i 关于 id 的对称点，即上图的 j 点
             * p[i] str 以 i 为中心点的最长回文字符串的半径
             */
            if (i < mx) p[i] = min(p[2 * id - i], mx - i); // key code
            else p[i] = 1;

            while (str[i - p[i]] == str[i + p[i]]) p[i]++;

            // 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，
            // 这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
            if (mx < i + p[i]) {
                id = i;
                mx = i + p[i];
            }

            if (p[i] - 1 > max) {
                max = p[i] - 1;
                maxi = i;
            }
        }

        for (auto x : p) {
            cout << x;
        }
        cout << endl;
        cout << maxi << endl;

        // 01234
        // cbbda
        // 0123456789 10 11 12
        // ^#c#b#b#d# a  #  $
        // 0
        // a
        // 01234
        // ^#a#$
        // i = (c + 1) * 2
        // c = i / 2 - 1
        int r = (p[maxi] - 1) / 2;
        if (maxi % 2 == 0) {
            int c = maxi / 2 - 1;
            return s.substr(c - r, p[maxi] - 1);
        }
        else {
            int c1 = maxi / 2 - 1;
            return s.substr(c1 - r + 1, p[maxi] - 1);
        }
    }
};

int main(int argc, char* argv[]) {

    string s = argc >= 2 ? argv[1] : "babad";

    Solution solution;
    cout << solution.Manacher(s) << endl;

    return 0;
}
