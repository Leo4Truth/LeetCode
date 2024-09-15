/**
 * @link https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
 * 
 * @difficulty middle
 * 
 * @tag 滑动窗口
 * @tag slide window
 * @tag 定长滑动窗口
 * @tag fixed slide window
 */
public class Solution1343NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int n = arr.length;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int sumThreshold = threshold * k;
        int count = 0;

        if (sum >= sumThreshold) {
            count++;
        }

        for (int r = k; r < n; r++) {
            int l = r - k;
            sum -= arr[l];
            sum += arr[r];
            if (sum >= sumThreshold) {
                count++;
            }
        }

        return count;
    }
}
