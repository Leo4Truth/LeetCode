#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//#define DEBUG

using namespace std;

class Solution {
public:
    virtual bool pyramidTransition(string bottom, vector<string>& allowed) = 0;
};

class Solution_dfs : public Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int w = bottom.length();
        int h = w;
        int n = allowed.size();

        unordered_map<string, vector<char>> map;
        for (auto& tri : allowed) {
            string base = tri.substr(0, 2);
            if (map.count(base) == 0) map[base] = {tri[2]};
            else map[base].push_back(tri[2]);
        }

#ifdef DEBUG
        cout << endl << "map: " << endl;
        for (auto entry : map) {
            cout << entry.first << ": ";
            for (auto c : entry.second) cout << c << " ";
            cout << endl;
        }
        cout << endl;
#endif // DEBUG

        vector<string> pyramid;
        pyramid.push_back(bottom);
        for (int row = 1; row < h; row++) pyramid.push_back(bottom.substr(0, w - row));

#ifdef DEBUG
        cout << "pyramid: " << endl;
        for (auto row : pyramid) cout << row << endl;
        cout << endl;
#endif // DEBUG

        bool found = false;
        dfs(pyramid, map, 1, 0, found);

        return found;
    }

private:
    void dfs(vector<string>& pyramid, unordered_map<string, vector<char>>& map, int row, int col, bool& found) {
        if (found) return;
#ifdef DEBUG
        cout << "row: " << row << ", col: " << col << ", pyramid: " << endl;
        for (auto row : pyramid) cout << row << endl;
        cout << endl;
#endif // DEBUG
        int h = pyramid.size();
        int w = pyramid[0].size();

        int currW = pyramid[row].length();

        string base = "";
        base.push_back(pyramid[row - 1][col]);
        base.push_back(pyramid[row - 1][col + 1]);
        if (map.count(base) == 0) return;
        if (row == h - 1 && col == 0) {
            found = true;
            return;
        }
        for (char c : map[base]) {
            pyramid[row][col] = c;
            // prune
            if (col > 0) {
                base[0] = pyramid[row][col - 1];
                base[1] = pyramid[row][col];
                if (map.count(base) == 0) continue;
            }
            int nextCol = (col + 1) % currW;
            int nextRow = nextCol == col + 1 ? row : row + 1;
            dfs(pyramid, map, nextRow, nextCol, found);
        }
    }
};

int main(int argc, char* argv[]) {
    string bottom = argc >= 1 ? argv[1] : "";
    int n = argc >= 2 ? stoi(argv[2]) : 0;
    vector<string> allowed;
    for (int i = 0; i < n; i++) {
        string tri;
        cin >> tri;
        allowed.push_back(tri);
    }

    Solution *solution = nullptr;

    solution = new Solution_dfs();
    cout << solution->pyramidTransition(bottom, allowed) << endl;

    return 0;
}
