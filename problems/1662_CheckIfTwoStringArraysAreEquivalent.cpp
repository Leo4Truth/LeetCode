#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual_1(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        for (int i = 0; i < word1.size(); i++) w1.append(word1[i]);
        for (int i = 0; i < word2.size(); i++) w2.append(word2[i]);
        return w1 == w2;
    }
    
    bool arrayStringsAreEqual_2(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;

        int n1 = word1.size();
        int n2 = word2.size();
        while (i1 < n1 && j1 < word1[i1].size() && i2 < n2 && j2 < word2[i2].size()) {
            cout << "(" << i1 << "," << j1 << ")" << ", " << "(" << i2 << "," << j2 << "), ";
            cout << word1[i1][j1] << ", " << word2[i2][j2] << endl;
            if (word1[i1][j1] != word2[i2][j2]) return false;

            if (j1 == word1[i1].length() - 1) {
                j1 = 0;
                i1++;
            }
            else j1++;

            if (j2 == word2[i2].length() - 1) {
                j2 = 0;
                i2++;
            }
            else j2++;
        }

        cout << i1 << ", " << i2 << endl;
        if (i1 == n1 && i2 == n2) return true;

        return false;
    }
};

int main(int argc, char* agrv[]) {
    int n1, n2;
    vector<string> word1, word2;

    cout << "please input n1: ";
    cin >> n1;
    cout << "please input " << n1 << " strings for word1: " << endl;
    for (int i = 0; i < n1; i++) {
        string str;
        cin >> str;
        word1.push_back(str);
    }

    
    cout << "please input n2: ";
    cin >> n2;
    cout << "please input " << n2 << " strings for word2: " << endl;
    for (int i = 0; i < n2; i++) {
        string str;
        cin >> str;
        word2.push_back(str);
    }

    Solution solution;
    cout << "Result: " << solution.arrayStringsAreEqual_2(word1, word2) << endl;

    return 0;
}