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
    virtual string alienOrder(vector<string>& words) = 0;
};

class Solution_TopologySortDFS : public Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (string & word : words) {
            for (char c : word) {
                if (!edges.count(c)) edges[c] = vector<char>();
            }
        }
        for (int i = 1; i < n && valid; i++) {
            addEdge(words[i - 1], words[i]);
            if (!valid) return "";
        }
        order = string(edges.size(), ' ');
        index = edges.size() - 1;
        for (auto [u, _] : edges) {
            if (!states.count(u)) dfs(u);
            if (!valid) return "";
        }
        return order;
    }

private:
    const int VISITING = 1, VISITED = 2;
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> states;
    bool valid = true;
    string order;
    int index;

    void addEdge(string before, string after) {
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length) {
            char c1 = before[index], c2 = after[index];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                break;
            }
            index++;
        }
        if (index == length && length1 > length2) {
            valid = false;
        }
    }

    void dfs(char u) {
        states[u] = VISITING;
        for (char v : edges[u]) {
            if (!states.count(v)) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (states[v] == VISITING) {
                valid = false;
                return;
            }
        }
        states[u] = VISITED;
        order[index] = u;
        index--;
    }
};

class Solution_TopologySortBFS : public Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (string & word : words) {
            for (char c : word) {
                if (!edges.count(c)) edges[c] = vector<char>();
            }
        }
        for (int i = 1; i < n && valid; i++) {
            addEdge(words[i - 1], words[i]);
        }

        if (!valid) return "";

        queue<char> q;
        for (auto [u, _] : edges) {
            if (!indegrees.count(u)) q.emplace(u);
        }
        string order;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            order.push_back(u);
            for (char v : edges[u]) {
                indegrees[v]--;
                if (indegrees[v] == 0) q.emplace(v);
            }
        }
        return order.size() == edges.size() ? order : "";
    }

private:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> indegrees;
    bool valid = true;

    void addEdge(string before, string after) {
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length) {
            char c1 = before[index], c2 = after[index];
            if (c1 != c2) {
                edges[c1].emplace_back(c2);
                indegrees[c2] += 1;
                break;
            }
            index++;
        }
        if (index == length && length1 > length2) valid = false;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    Solution *solution = nullptr;

    solution = new Solution_TopologySortDFS();
    cout << "DFS: " << solution->alienOrder(words) << endl;

    solution = new Solution_TopologySortBFS();
    cout << "BFS: " << solution->alienOrder(words) << endl;

    return 0;
}
