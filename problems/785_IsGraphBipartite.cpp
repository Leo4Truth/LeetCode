#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution785 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return false;

        vector<int> color(n, -1);
        for (int s = 0; s < n; s++) {
            if (color[s] == -1) {
                stack<int> stk;
                stk.push(s);
                color[s] = 0;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            stk.push(neighbor);
                            color[neighbor] = color[node] ^ 1;
                        }
                        else if (color[neighbor] == color[node]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 4;
    //int e = argc >= 3 ? stoi(argv[2]) : 4;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++) {
        vector<int> adjList;
        int ee;
        cin >> ee;
        for (int j = 0; j < ee; j++) {
            int x;
            cin >> x;
            adjList.push_back(x);
        }
        graph.push_back(adjList);
    }

    Solution785 solution;
    cout << solution.isBipartite(graph) << endl;

    //system("pause");
    return 0;
}
