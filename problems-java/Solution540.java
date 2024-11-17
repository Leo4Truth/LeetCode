/**
 * @link https://leetcode.cn/problems/single-element-in-a-sorted-array/description/
 * 
 * @level middle
 * @tag 
 * @tag 
 * 
 * @constraints: 1 <= nums.length <= 10^5, 0 <= nums[i] <= 10^5
 */
class Solution540 {
    /**
     * @time complexity: O(n)
     * @space complexity: O(1)
     */
    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        for (int i = 1; i < nums.length; i++) {
            if (i % 2 == 1 && nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }
        return nums[nums.length - 1];
    }

    /**
     * 二分
     * @time complexity: O(logn)
     * @space complexity: O(1)
     */
    public int singleNonDuplicateBisection(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int l = -1, r = nums.length / 2;
        while (l + 1 < r) {
            int mid = (l + r) >>> 1;
            if (nums[mid * 2] != nums[mid * 2 + 1]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return nums[r * 2];
    }

    public static void main(String[] args) {
        System.out.println(2 >> 1);
        System.out.println(2 >>> 1);
        System.out.println(2 / 2);
        System.out.println(Integer.MAX_VALUE >> 1);
        System.out.println(Integer.MAX_VALUE >>> 1);
        System.out.println(Integer.MAX_VALUE / 2);

        Solution540 solution540 = new Solution540();

        int nums1[] = {1,1,2,3,3,4,4,8,8};
        int ans1 = solution540.singleNonDuplicate(nums1);
        System.out.println("ans1: " + ans1);

        int nums2[] = {3,3,7,7,10,11,11};
        int ans2 = solution540.singleNonDuplicate(nums2);
        System.out.println("ans2: " + ans2);


        ans1 = solution540.singleNonDuplicateBisection(nums1);
        System.out.println("ans1 bisection: " + ans1);

        ans2 = solution540.singleNonDuplicateBisection(nums2);
        System.out.println("ans2 bisection: " + ans2);
    }
}