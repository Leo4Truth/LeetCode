
import java.util.HashSet;
import java.util.Set;

/**
 * @link https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked
 * 
 * @level middle
 */
public class Solution128 {
    public int longestConsecutive(int[] nums) {
        int longest = 0;
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        for (int num : set) {
            if (!set.contains(num - 1)) {
                int currentNum = num;
                int len = 1;

                while (set.contains(currentNum + 1)) {
                    currentNum += 1;
                    len += 1;
                }

                longest = Math.max(longest, len);
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        Solution128 solution128 = new Solution128();

        int[] nums1 = {100,4,200,1,3,2};
        System.out.println("ans1: " + solution128.longestConsecutive(nums1));

        int[] nums2 = {0,3,7,2,5,8,4,6,0,1};
        System.out.println("ans2: " + solution128.longestConsecutive(nums2));
    }
}