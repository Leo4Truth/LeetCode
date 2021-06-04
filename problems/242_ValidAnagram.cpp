#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution242 {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        unordered_map<char, int> cnt;
        for (int i = 0; i < n1; i++) cnt[s[i]]++;
        for (int i = 0; i < n2; i++) {
            if (cnt.find(t[i]) == cnt.end()) return false;
            else {
                cnt[t[i]]--;
                if (cnt[t[i]] < 0) return false;
            }
        }
        for (auto it : cnt) {
            if (it.second != 0) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "anagram";
    string t = argc >= 3 ? argv[2] : "nagaram";

    Solution242 solution;
    cout << solution.isAnagram(s, t) << endl;

    //system("pause");
    return 0;
}
