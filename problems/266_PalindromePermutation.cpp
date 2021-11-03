#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        int oddCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            dict[s[i]]++;
            if (dict[s[i]] % 2 == 1) oddCnt++;
            else oddCnt--;
        }

        return oddCnt <= 1;
    }
};

int main(int argc, char *argv[]) {
    string s;
    if (argc == 2) s = argv[1];
    else {
        cout << "please input s: " << endl;
        cin >> s;
    }

    Solution solution;
    cout << solution.canPermutePalindrome(s) << endl;

    return 0;
}