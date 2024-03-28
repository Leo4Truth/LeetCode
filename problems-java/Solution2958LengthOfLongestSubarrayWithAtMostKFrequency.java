import java.util.HashMap;

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

    public static void main(String[] args) {
        Solution2958LengthOfLongestSubarrayWithAtMostKFrequency solution2958LengthOfLongestSubarrayWithAtMostKFrequency =
                new Solution2958LengthOfLongestSubarrayWithAtMostKFrequency();

        int[] nums1 = {1,2,3,1,2,3,1,2};
        int k1 = 2;
        System.out.println(solution2958LengthOfLongestSubarrayWithAtMostKFrequency.maxSubarrayLength(nums1, k1));
    }
}
