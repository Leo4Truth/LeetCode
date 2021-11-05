#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

class Solution {
public:
    virtual int rand10() = 0;
    
    int rand7() {
        return rand() % 7 + 1;
    }
};

class Solution_rejectSample : public Solution {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }

private:
};

class Solution_adv : public Solution {
public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20) {
                return 1 + (idx - 1) % 10;
            }
        }
    }

private:
};

int main(int argc, char* argv[]) {
    /* initialize random seed: */
    srand (time(NULL));

    Solution *solution = nullptr;

    solution = new Solution_rejectSample();
    cout << "reject sample: ";
    for (int i = 0; i < 10; i++) cout << solution->rand10() << " ";
    cout << endl;

    solution = new Solution_adv();
    cout << "advanced     : ";
    for (int i = 0; i < 10; i++) cout << solution->rand10() << " ";
    cout << endl;

    return 0;
}
