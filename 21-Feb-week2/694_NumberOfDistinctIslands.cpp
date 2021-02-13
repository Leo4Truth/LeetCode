#include <iostream>
#include <vector>

using namespace std;

class Solution694 {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 4;
    int n = argc >= 3 ? stoi(argv[2]) : 5;
    
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    

    Solution694 solution;
    cout << solution.numDistinctIslands(grid) << endl;

    //system("pause");
    return 0;
}
