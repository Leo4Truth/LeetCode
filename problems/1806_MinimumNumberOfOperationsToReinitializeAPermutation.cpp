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

using namespace std;

class Solution {
public:
    virtual int reinitializePermutation(int n) = 0;
};

class Solution_sim : public Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> origin(n);
        vector<int> perm(n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            origin[i] = i;
            perm[i] = i;
            arr[i] = 0;
        }

        int step = 0;
        do {
            step++;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) arr[i] = perm[i / 2];
                else arr[i] = perm[n / 2 + (i - 1) / 2];
            }
            for (int i = 0; i < n; i++) {
                perm[i] = arr[i];
            }
        } while (!compare(origin, arr));

        return step;
    }

private:
    bool compare(vector<int>& a, vector<int>& b) {
        int n = a.size();
        if (b.size() != n) return false;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};


class Solution_math : public Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        int step = 1, pow2 = 2;
        while (pow2 != 1) {
            step++;
            pow2 = pow2 * 2 % (n - 1);
        }
        return step;
    }

private:
};


int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_sim();
    cout << solution->reinitializePermutation(n) << endl;
    solution = new Solution_math();
    cout << solution->reinitializePermutation(n) << endl;

#ifdef DEBUG
    for (int nn = 2; nn <= 64; nn += 2) {
        cout << nn << ": " << solution->reinitializePermutation(nn) << endl;
    }

    for (int nn = 2; nn < 16; nn += 2) {
        cout << "n = " << nn << endl;
        for (int i = 0; i < nn; i++) {
            cout << "\t" <<  i << " <- ";
            int x = i / 2;
            int y = nn / 2 + (i - 1) / 2;
            if (i % 2 == 0) cout << x << endl;
            else cout << y << endl;
        }
    }
#endif // DEBUG

    return 0;
}
