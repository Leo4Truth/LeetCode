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
    int findComplement(int num) {
        long mask = 1;
        long completment = num;
        while (mask <= num) {
            completment ^= mask;
            mask <<= 1;
        }
        return (int) completment;
    }

    int findComplement_official(int num) {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i) {
            if (num >= (1 << i)) {
                highbit = i;
            }
            else {
                break;
            }            
        }
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return num ^ mask;
    }
};

int main(int argc, char* argv[]) {
    int num = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.findComplement(num) << endl;

    return 0;
}
