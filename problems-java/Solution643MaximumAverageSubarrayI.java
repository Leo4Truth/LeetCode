/**
 * @link https://leetcode.cn/problems/maximum-average-subarray-i/
 * 
 * @difficulty easy
 * 
 * @tag 滑动窗口
 * @tag slide window
 * @tag 定长滑动窗口
 * @tag fixed slide window
 */
public class Solution643MaximumAverageSubarrayI {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        for (int r = k; r < n; r++) {
            int l = r - k;
            sum -= nums[l];
            sum += nums[r];
            maxSum = sum > maxSum ? sum : maxSum;
        }

        return maxSum * 1.0 / k;
    }
}
