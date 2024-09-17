/**
 * @link https://leetcode.cn/problems/maximum-erasure-value/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution1695MaximumErasureValue {

    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[10001]; // 1 <= nums[i] <= 10000
        int max = 0;
        int sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[nums[r]]++;
            sum += nums[r];
            while (cnt[nums[r]] > 1) {
                cnt[nums[l]]--;
                sum -= nums[l];
                l++;
            }
            max = sum > max ? sum : max;
        }
        return max;
    }

}
