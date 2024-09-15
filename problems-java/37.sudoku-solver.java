/*
 * @lc app=leetcode id=37 lang=java
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
    private static final char[] nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


    public void solveSudoku(char[][] board) {
        solveSudokuRecursive(board, 0, 0, '1');
    }

    private boolean isValid(char[][] board, int x, int y, char ch) {
        for (int i = 0; i < 9; i++) {
            if (i == x) {
                continue;
            }
            if (board[i][y] == ch) {
                return false;
            }
        }
        for (int j = 0 ; j < 9; j++) {
            if (j == y) {
                continue;
            }
            if (board[x][j] == ch) {
                return false;
            }
        }
        return true;
    }

    private void solveSudokuRecursive(char[][] board, int index) {
        if (index == 81) {
            return;
        }
        int x = index / 9;
        int y = index % 9;
        if (board[x][y] == '.') {
            for (Character num : nums) {
                board[x][y] = num;
                if (isValid(board, x, y, num)) {
                    solveSudokuRecursive(board, index + 1);
                }
                board[x][y] = '.';
            }
        } else {
            solveSudokuRecursive(board, index + 1);
        }
    }
}
// @lc code=end

