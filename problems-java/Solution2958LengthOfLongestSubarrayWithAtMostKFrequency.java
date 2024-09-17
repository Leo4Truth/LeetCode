import java.util.Map;
import java.util.HashMap;

/**
 * @link https://leetcode.cn/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution2958LengthOfLongestSubarrayWithAtMostKFrequency {

    public int maxSubarrayLength(int[] nums, int k) {
        int left = 0, right = 0, ans = 0;

        HashMap<Integer, Integer> map = new HashMap<>();

        while (left < nums.length && right < nums.length) {
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1);
            while (map.get(nums[right]) > k) {
                map.put(nums[left], map.get(nums[left]) - 1);
                left++;
            }
            ans = Math.max(ans, right - left + 1);
            right++;
        }
        return ans;
    }

    /**
     * 2024-09-18
     * 
     * @param nums
     * @param k
     * @return
     */
    public int maxSubarrayLength1(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> cnt = new HashMap<>();
        int max = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt.put(nums[r], cnt.getOrDefault(nums[r], 0) + 1);
            while (cnt.getOrDefault(nums[r], 0) > k) {
                cnt.put(nums[l], cnt.get(nums[l]) - 1);
                l++;
            }
            max = r -l + 1 > max ? r - l + 1 : max;
        }
        return max;
    }

    public static void main(String[] args) {
        Solution2958LengthOfLongestSubarrayWithAtMostKFrequency solution2958LengthOfLongestSubarrayWithAtMostKFrequency =
                new Solution2958LengthOfLongestSubarrayWithAtMostKFrequency();

        int[] nums1 = {1,2,3,1,2,3,1,2};
        int k1 = 2;
        System.out.println(solution2958LengthOfLongestSubarrayWithAtMostKFrequency.maxSubarrayLength(nums1, k1));
    }
}
