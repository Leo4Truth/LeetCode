#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void helper(vector<char>& s, int len) {
        if (len == 0) return;
        else {
            char tmp = s[0];
            for (int i = 0; i < len - 1; i++) s[i] = s[i + 1];
            s[len - 1] = tmp;
            for (int i = 0; i < s.size(); i++) cout << s[i];
            cout << endl;
            helper(s, len - 1);
        }
    }

    void reverseString_rec(vector<char>& s) {
        helper(s, s.size());
    }
    
    void reverseString_2ptr(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};

int main(int argc, char *argv[]) {
    string str;
    if (argc == 2) str = stoi(argv[1]);
    else {
        cout << "please input a string: ";
        cin >> str;
    }

    vector<char> s;
    for (int i = 0; i < str.length(); i++) s.push_back(str[i]);

    Solution solution;
    solution.reverseString_2ptr(s);
    for (int i = 0; i < str.length(); i++) cout << s[i];
    cout << endl;

    return 0;
}