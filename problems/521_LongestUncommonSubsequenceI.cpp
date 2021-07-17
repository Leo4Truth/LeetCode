#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a.compare(b) == 0 ? -1 : max(a.length(), b.length());
    }
};

int main(int argc, char* argv[]) {
    string a = argc >= 2 ? argv[1] : "";
    string b = argc >= 3 ? argv[2] : "";

    Solution solution;
    cout << solution.findLUSlength(a, b) << endl;

    //system("pause");
    return 0;
}
