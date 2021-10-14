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
    vector<string> fizzBuzz(int n) {
        vector<string> anwser;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                anwser.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                anwser.push_back("Fizz");
            } else if (i % 5 == 0) {
                anwser.push_back("Buzz");
            } else {
                anwser.push_back(to_string(i));
            }
        }
        return anwser;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    vector<string> anwser = solution.fizzBuzz(n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << "\"" << anwser[i] << "\"";
        if (i < n - 1) cout << ",";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
