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
    virtual int timeRequiredToBuy(vector<int>& tickets, int k) = 0;
};

class Solution_init : public Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

        int time = 0;
        for (int i = 0; i < n; i++) {
            if (tickets[i] < tickets[k]) time += tickets[i];
            else {
                if (i <=k) time += tickets[k];
                else time += (tickets[k] - 1);
            }
        }

        return time;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> tickets;
    for (int i = 0; i < n; i++) {
        int ticket;
        cin >> ticket;
        tickets.push_back(ticket);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->timeRequiredToBuy(tickets, k) << endl;

    return 0;
}
