/**
 * @link https://leetcode.cn/problems/maximize-win-from-two-segments/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution2555MaximizeWinFromTwoSegments {

    /**
     * Time Complexity: O(N^2)
     * Space Complexity: O(1)
     * 
     * @param prizePositions
     * @param k
     * @return
     */
    public int maximizeWin(int[] prizePositions, int k) {
        int n = prizePositions.length;
        if (n == 0) {
            return 0;
        }

        int max = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (prizePositions[r] - prizePositions[l] > k) {
                l++;
            }

            // 第一个区间的长度 = 第一个区间的获奖数
            int len1 = r - l + 1;
            
            
            // 分两种情况
            // 1. 第一个区间扩张到了极限还没覆盖整个prizePositions, 此时考虑第二个区间, 第二个区间的左边界ll从r + 1开始
            // 2. 第二个区间扩展到了极限已经覆盖了整个prizePositions, 此时不需要考虑第二个区间了, 直接结算
            if (r < n - 1 && prizePositions[r + 1] - prizePositions[l] > k) {
                int ll = r + 1;
                for (int rr = ll; rr < n; rr++) {
                    while (prizePositions[rr] - prizePositions[ll] > k) {
                        ll++;
                    }
                    max = len1 + rr - ll + 1 > max ? len1 + rr - ll + 1 : max;
                }
            } else if (r == n - 1) {
                max = len1 > max ? len1 : max;
            }
        }
        return max;
    }

    /**
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     * 
     * @param prizePositions
     * @param k
     * @return
     */
    public int maximizeWin1(int[] prizePositions, int k) {
        int ans = 0;
        for (int l1 = 0, r1 = 0, l2 = 0, r2 = 0, firstMax = 0; r2 < prizePositions.length; r2++) {
            while (prizePositions[r2] - prizePositions[l2] > k) {
                l2++;
            }
            for (; r1 < l2; r1++) {
                while (prizePositions[r1] - prizePositions[l1] > k) {
                    l1++;
                }
                firstMax = Math.max(firstMax, r1 - l1 + 1);
            }
            ans = Math.max(ans, r2 - l2 + 1 + firstMax);
        }
        return ans;
    }

}
