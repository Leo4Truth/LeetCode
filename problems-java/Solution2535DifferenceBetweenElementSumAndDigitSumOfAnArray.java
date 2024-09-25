import java.util.*;;

/**
 * @link https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
 * 
 * @level easy
 */
public class Solution2535DifferenceBetweenElementSumAndDigitSumOfAnArray {

    public int differenceOfSum(int[] nums) {
        int sum = 0;
        int digitSum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            while (nums[i] > 0) {
                digitSum += nums[i] % 10;
                nums[i] /= 10;
            }
        }
        return Math.abs(sum - digitSum);
    }

    public static void main(String[] args) {
        Solution2535DifferenceBetweenElementSumAndDigitSumOfAnArray solution = new Solution2535DifferenceBetweenElementSumAndDigitSumOfAnArray();
        int[] nums1 = {1,15,6,3};
        System.out.println(solution.differenceOfSum(nums1));
        int[] nums2 = {1,2,3,4};
        System.out.println(solution.differenceOfSum(nums2));
    }
}
