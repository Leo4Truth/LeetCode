#include <iostream>
#include <vector>

using namespace std;

class Solution119 {
public:
    vector<int> getRow_bf(int rowIndex) {
        vector<vector<int>> res;

        for (int i = 0; i < rowIndex + 1; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++)
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            res.push_back(row);
        }

        return res[rowIndex];
    }

    vector<int> getRow_dp_opt(int rowIndex) {
        int len = rowIndex + 1;
        vector<int> row(len, 1);

    	for (int i = 0; i < len; i++) {
            int rightmost = i;
    		for (int j = rightmost - 1; j > 0; j--)
                row[j] = row[j] + row[j - 1];
    	}

        return row;
    }
};