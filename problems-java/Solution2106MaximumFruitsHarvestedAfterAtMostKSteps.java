/**
 * @link https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/description/?envType=problem-list-v2&envId=7NLUuUun
 * 
 * @level middle
 * 
 * 
 */
public class Solution2106MaximumFruitsHarvestedAfterAtMostKSteps {

    /**
     * 外层循环 遍历所有 r, l 组合
     * 内层循环 遍历水果集合计算 r, l 对应的 sum
     * 
     * 时间复杂读: O(mn) 超时
     * 
     * @param fruits
     * @param startPos
     * @param k
     * @return
     */
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int max = 0;
        for (int l = startPos - k >= 0 ? startPos - k : 0; l <= startPos; l++) {
            int r = startPos;
            if ((startPos - l) * 3 <= k) {
                r = k - (startPos - l) * 2 + startPos;
            } else {
                r = (k - (startPos - l)) / 2 + startPos;
            }

            int sum = 0;
            for (int[] fruit : fruits) {
                if (fruit[0] >= l && fruit[0] <= r) {
                    sum += fruit[1];
                }
                if (fruit[0] > r) {
                    break;
                }
            }
            System.out.printf("l: %d, r: %d, sum: %d\n", l, r, sum);
            max = sum > max ? sum : max;
        }
        return max;
    }

    /**
     * 直接遍历水果集合计算, 滑动窗口判断 r, l 是否符合k
     * 
     * 时间复杂读: O(mn) 超时
     * 
     * @param fruits
     * @param startPos
     * @param k
     * @return
     */
    public int maxTotalFruits1(int[][] fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.length;
        int sum = 0;
        int ans = 0;
        // 每次固定住窗口右边界
        while (right < n) {
            sum += fruits[right][1];
            // 移动左边界
            while (left <= right && step(fruits, startPos, left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = Math.max(ans, sum);
            right++;
        }
        return ans;
    }

    public int step(int[][] fruits, int startPos, int left, int right) {
        return Math.min(Math.abs(startPos - fruits[right][0]), Math.abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
    }

}
