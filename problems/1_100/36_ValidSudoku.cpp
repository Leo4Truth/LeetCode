#include <iostream>
#include <vector>

using namespace std;

class Solution36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> record(10, 0);
        // rows
        for (int row = 0; row < 9; row++) {
            initRecord(record);
            for (int i = 0; i < 9; i++) {
                //cout << "i, j = " << row << ", " << i << "; val = " << board[row][i] << endl;
                if (board[row][i] == '.')
                    continue;
                if (board[row][i] > '9' || board[row][i] < '1')
                    return false;
                if (record[board[row][i] - '0']) {
                    cout << "row: " << board[row][i] - '0' << endl;
                    return false;
                }
                else
                    record[board[row][i] - '0'] = true;
            }
            cout << endl;
        }
        // cols
        for (int col = 0; col < 9; col++) {
            initRecord(record);
            for (int i = 0; i < 9; i++) {
                //cout << "i, j = " << i << ", " << col << "; val = " << board[i][col] << endl;
                if (board[i][col] == '.')
                    continue;
                if (board[i][col] > '9' || board[i][col] < '1')
                    return false;
                if (record[board[i][col] - '0']) {
                    cout << "col: " << board[i][col] - '0' << endl;
                    return false;
                }
                else
                    record[board[i][col] - '0'] = true;
            }
            cout << endl;
        }
        // 3x3
        int leftUp[9][2] = {
            {0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}
        };
        for (int k = 0; k < 9; k++) {
            initRecord(record);
            int i = leftUp[k][0], j = leftUp[k][1];
            //cout << "k = " << k << endl;
            for (int l = 0; l < 9; l++) {
                //cout << "l = " << l << "; i, j = " << i << ", " << j << "; val = " << board[i][j] << endl;
                if (board[i][j] == '.') {
                    if (l == 2 || l == 5) {
                        i++;
                        j -= 2;
                    }
                    else j++;
                    continue;
                }
                if (board[i][j] > '9' || board[i][j] < '1')
                    return false;
                if (record[board[i][j] - '0']) {
                    cout << "3x3: " << board[i][j] - '0' << endl;
                    return false;
                }
                else
                    record[board[i][j] - '0'] = true;

                if (l == 2 || l == 5) {
                    i++;
                    j -= 2;
                }
                else j++;
            } 
        }
        return true;
    }

    void initRecord(vector<bool>& record) {
        for (int i = 0; i < record.size(); i++)
            record[i] = false;
    }
};

int main36() {
    vector<vector<char>> sudoku(9);
    char sudokuArray1[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    char sudokuArray2[9][9] = {
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    };
    Solution36 solution;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            sudoku[i].push_back(sudokuArray1[i][j]);
    cout << solution.isValidSudoku(sudoku) << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            sudoku[i][j] = sudokuArray2[i][j];
    cout << solution.isValidSudoku(sudoku) << endl;
    system("pause");
    return 0;
}