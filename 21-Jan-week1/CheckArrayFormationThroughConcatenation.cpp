#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int m = pieces.size();

        unordered_map<int, pair<int, int>> map;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < pieces[j].size(); k++) {
                    // map[i] = (j, k) means arr[i] matches pieces[j][k] 
                    if (arr[i] == pieces[j][k])
                        map[i] = pair<int, int>(j, k);
                }
            }
            // if any integer in arr not found in all pieces, return false
            if (map.find(i) == map.end()) return false;
        }

        for (int i = 0; i < n - 1; i++) {
            if (map[i].first == map[i + 1].first) {
                if (map[i].second != map[i + 1].second - 1) return false;
            }
            else {
                if (map[i].second != pieces[map[i].first].size() - 1) return false;
            }
        }

        int sum = 0;
        for (int j = 0; j < m; j++) sum += pieces[j].size();
        
        return sum == map.size();
    }
};

int main() {
    int n = 0, m = 0;
    vector<int> arr;
    vector<vector<int>> pieces;

    cout << "please input length of arr: ";
    cin >> n;
    cout << "please input arr:";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "please input length of pieces: ";
    cin >> m;
    cout <<"please input " << m << " pieces, each line a piece, begin with the length of the piece: " << endl;
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        vector<int> piece;
        for (int j = 0; j < len; j++) {
            int x;
            cin >> x;
            piece.push_back(x);
        }
        pieces.push_back(piece);
    }

    Solution solution;
    cout << "result: " << solution.canFormArray(arr, pieces) << endl;

    return 0;
}
