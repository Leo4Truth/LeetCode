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

class RecentCounter {
public:
    RecentCounter() {

    }
    
    virtual int ping(int t) = 0;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/**
 * @brief vector store all time with request, and search from the back
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class RecentCounter_vector : public RecentCounter {
public:
    RecentCounter_vector() {

    }
    
    int ping(int t) {
        timeWithRequest.push_back(t);
        int cnt = 0;
        for (int i = timeWithRequest.size() - 1; i >= 0 && t - timeWithRequest[i] <= 3000; i--) cnt++;
        return cnt;
    }

private:
    // store the time with request
    vector<int> timeWithRequest;
};

/**
 * @brief vector store all time with request, pop time of request out of range [t - 3000, t] (earlier)
 * Time Complexity: O(1) (Amortized, because every element pop at most once)
 * Space Complexity: O(L) (L is the largest number of elements in the queue)
 */
class RecentCounter_queue : public RecentCounter {
public:
    RecentCounter_queue() {

    }
    
    int ping(int t) {
        timeWithRequest.push(t);
        while (!timeWithRequest.empty() && t - timeWithRequest.front() > 3000) timeWithRequest.pop();
        return timeWithRequest.size();
    }

private:
    // store the time with request
    queue<int> timeWithRequest;
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> requests;
    for (int i = 0; i < n; i++) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    RecentCounter *recentCounter = nullptr;

    // vector
    recentCounter = new RecentCounter_vector();
    cout << "vector: [";
    for (int i = 0; i < n; i++) {
        cout << recentCounter->ping(requests[i]);
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    // queue
    recentCounter = new RecentCounter_queue();
    cout << "queue: [";
    for (int i = 0; i < n; i++) {
        cout << recentCounter->ping(requests[i]);
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
