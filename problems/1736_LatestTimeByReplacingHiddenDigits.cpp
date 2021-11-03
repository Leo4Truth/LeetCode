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
    string maximumTime(string time) {
        string validTime = "00:00";
        validTime[0] = time[0] != '?' ? time[0] : (time[1] >= '4' ? '1' : '2');
        validTime[1] = time[1] != '?' ? time[1] : (time[0] == '2' ? '3' : '9');
        if (time[0] == '?' && time[1] == '?') {
            validTime[0] = '2';
            validTime[1] = '3';
        }
        validTime[3] = time[3] != '?' ? time[3] : '5';
        validTime[4] = time[4] != '?' ? time[4] : '9';
        return validTime;
    }
};

int main(int argc, char* argv[]) {
    string time = argc >= 2 ? argv[1] : "??:??";

    Solution solution;
    cout << solution.maximumTime(time) << endl;

    //system("pause");
    return 0;
}
