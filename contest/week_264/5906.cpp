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
    int countValidWords(string sentence) {
        int cnt = 0;
        for (int i = 0; i < sentence.size(); i++) {
            while (i < sentence.size() && sentence[i] == ' ') i++;
            if (i == sentence.size()) break;
            if (sentence[i] < 'a' || sentence[i] > 'z') {
                while (i < sentence.size() && sentence[i] != ' ') i++;
                if (i == sentence.size()) break;
            }
            int connector_cnt = 0;
            while
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    string sentence = "hello world!";

    Solution solution;
    cout << solution.countValidWords(sentence) << endl;

    return 0;
}
