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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1);
        heap.push(1);
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for (int prime : primes) {
                long next = curr * prime;
                if (seen.insert(next).second) {
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> primes;
    for (int i = 0; i < m; i++) {
        int prime;
        cin >> prime;
        primes.push_back(prime);
    }

    Solution solution;
    cout << solution.nthSuperUglyNumber(n, primes) << endl;

    //system("pause");
    return 0;
}
