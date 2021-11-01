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
    virtual int minimumOperations(vector<int>& nums, int start, int goal) = 0;
};

/**
 * @brief One Way BFS
 * because only [0, 1000] valid, use a vector<bool> visited to record whether a num is visited
 * I use a unordered_map<int, int> (or unordered_set<int> equally), though can also have correct anwser, got LTE at cae 41
 * 执行用时: 44 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗: 8.5 MB, 在所有 C++ 提交中击败了100.00%的用户
 */
class Solution_oneWayBFS : public Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if (start == goal) return 0;
        
        int n = nums.size();
        if (n == 0) return -1;

        //unordered_map<int, int> minOp;
        //minOp[start] = 0;
        vector<bool> visited(1005, false);

        // curr, op
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        while (!q.empty()) {
            int curr = q.front().first;
            int op = q.front().second;
            q.pop();
            
            for (int i = 0; i < n; i++) {
                int next = curr + nums[i];
                if (next == goal) return op + 1;
                //if (next >= 0 && next <= 1000 && minOp.count(next) == 0 || minOp[next] > op + 1) {
                if (next >= 0 && next <= 1000 && visited[next] == false) {
                    q.push(make_pair(next, op + 1));
                    //minOp[next] = op + 1;
                    visited[next] = true;
                }
                
                next = curr - nums[i];
                if (next == goal) return op + 1;
                //if (next >= 0 && next <= 1000 && minOp.count(next) == 0 || minOp[next] > op + 1) {
                if (next >= 0 && next <= 1000 && visited[next] == false) {
                    q.push(make_pair(next, op + 1));
                    //minOp[next] = op + 1;
                    visited[next] = true;
                }
                
                next = curr ^ nums[i];
                if (next == goal) return op + 1;
                //if (next >= 0 && next <= 1000 && minOp.count(next) == 0 || minOp[next] > op + 1) {
                if (next >= 0 && next <= 1000 && visited[next] == false) {
                    q.push(make_pair(next, op + 1));
                    //minOp[next] = op + 1;
                    visited[next] = true;
                }
            }
        }

        return -1;
    }
};

/**
 * @brief Two Way BFS
 * MUST sort nums!
 * 执行用时: 56 ms, 在所有 C++ 提交中击败了100.00%的用户
 * 内存消耗: 9 MB, 在所有 C++ 提交中击败了20.00%的用户
 */
class Solution_twoWayBFS : public Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if (start == goal) return 0;
        
        int n = nums.size();
        if (n == 0) return -1;

        // key key key wtf
        sort(nums.begin(), nums.end());
        
        // need to record the distance of every visited num from start or goal
        vector<int> distanceFromStart(1005, -1);
        vector<int> distanceFromGoal(1005, -1);

        // curr, op
        queue<int> forwardQ;
        queue<int> backwardQ;
        forwardQ.push(start);
        backwardQ.push(goal);
        while (!forwardQ.empty() && !backwardQ.empty()) {
            if (forwardQ.size() <= backwardQ.size()) {
                // forward
                int curr = forwardQ.front();
                forwardQ.pop();
                // op count (distance) from start to current num
                int op = curr == start ? 0 : distanceFromStart[curr];
                
                for (int i = 0; i < n; i++) {
                    int next = curr + nums[i];
                    if (next == goal) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromGoal[next] != -1) return op + 1 + distanceFromGoal[next];
                        if (distanceFromStart[next] == -1) {
                            forwardQ.push(next);
                            distanceFromStart[next] = op + 1;
                        }
                    }
                    
                    next = curr - nums[i];
                    if (next == goal) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromGoal[next] != -1) return op + 1 + distanceFromGoal[next];
                        if (distanceFromStart[next] == -1) {
                            forwardQ.push(next);
                            distanceFromStart[next] = op + 1;
                        }
                    }
                    
                    next = curr ^ nums[i];
                    if (next == goal) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromGoal[next] != -1) return op + 1 + distanceFromGoal[next];
                        if (distanceFromStart[next] == -1) {
                            forwardQ.push(next);
                            distanceFromStart[next] = op + 1;
                        }
                    }
                }
            } else {
                // backward
                int curr = backwardQ.front();
                backwardQ.pop();
                // op count (distance) from goal to current num
                int op = curr == goal ? 0 : distanceFromGoal[curr];
                
                for (int i = 0; i < n; i++) {
                    int next = curr + nums[i];
                    if (next == start) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromStart[next] != -1) return op + 1 + distanceFromStart[next];
                        if (distanceFromGoal[next] == -1) {
                            backwardQ.push(next);
                            distanceFromGoal[next] = op + 1;
                        }
                    }
                    
                    next = curr - nums[i];
                    if (next == start) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromStart[next] != -1) return op + 1 + distanceFromStart[next];
                        if (distanceFromGoal[next] == -1) {
                            backwardQ.push(next);
                            distanceFromGoal[next] = op + 1;
                        }
                    }
                    
                    next = curr ^ nums[i];
                    if (next == start) return op + 1;
                    if (next >= 0 && next <= 1000) {
                        if (distanceFromStart[next] != -1) return op + 1 + distanceFromStart[next];
                        if (distanceFromGoal[next] == -1) {
                            backwardQ.push(next);
                            distanceFromGoal[next] = op + 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    int start = argc >= 2 ? stoi(argv[1]) : 0;
    int goal = argc >= 3 ? stoi(argv[2]) : 0;
    int n = argc >= 4 ? stoi(argv[3]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_oneWayBFS();
    cout << "One Way BFS: " << solution->minimumOperations(nums, start, goal) << endl;
    
    solution = new Solution_twoWayBFS();
    cout << "Two Way BFS: " << solution->minimumOperations(nums, start, goal) << endl;

    nums = {27,21,89,-37,23,-46,-82,-57,-23,-38,74,-35,-32,53,11,-62,9,-77,-25,-12,-50,33,-52,-10,-72,-16,50,-51,63,10,60,-94,15,65,20,-34,22,-41,-39,-30,-11,35,-63,-55,99,48,-92,-66,1};
    start = 92;
    goal = 819;

    cout << "The last case (51): " << endl;    
    solution = new Solution_oneWayBFS();
    cout << "One Way BFS: " << solution->minimumOperations(nums, start, goal) << endl;
    
    solution = new Solution_twoWayBFS();
    cout << "Two Way BFS: " << solution->minimumOperations(nums, start, goal) << endl;
    
    return 0;
}
