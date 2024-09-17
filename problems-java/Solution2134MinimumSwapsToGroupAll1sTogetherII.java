/**
 * @link https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii/
 * 
 * @level middle
 * 
 * 
 */
public class Solution2134MinimumSwapsToGroupAll1sTogetherII {

    /**
     * 
     * @param nums
     * @return
     */
    public int minSwaps(int[] nums) {
        int n = nums.length;

        // get num of one
        int m = 0;
        for (int i = 0; i < n; i++) {
            m += nums[i] == 1 ? 1 : 0;
        }
        if (m == n) {
            return 0;
        }

        // sliding window size = num of one
        // count is the num of zero in sliding window [i, (i + m - 1) % n]
        int count = 0;
        // init sliding windows
        for (int i = 0; i < m; i++) {
            if (nums[i] == 0) {
                count++;
            }
        }
        int minCount = count;
        
        for (int l = 0; l < n; l++) {
            int r = (l + m) % n;
            System.out.println("l: " + String.valueOf(l) + ", r: " + String.valueOf(r));
            if (nums[l] == 0) {
                count--;
            }
            if (nums[r] == 0) {
                count++;
            }
            minCount = count < minCount ? count : minCount;
        }

        return minCount;
    }

}
