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
    virtual int findTheWinner(int n, int k) = 0;
};

class Solution_simulationQueue : public Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 0; i < n; i++) q.emplace(i + 1);
        while (q.size() > 1) {
            for (int i = 1; i < k; i++) {
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }

private:
};

class Solution_mathRecursive : public Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) return 1;
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }

private:
};

class Solution_mathIterative : public Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_simulationQueue();
    cout << "simulation queue: " << solution->findTheWinner(n, k) << endl;

    solution = new Solution_mathRecursive();
    cout << "math recursive  : " << solution->findTheWinner(n, k) << endl;

    solution = new Solution_mathIterative();
    cout << "math iterative  : " << solution->findTheWinner(n, k) << endl;

    return 0;
}
