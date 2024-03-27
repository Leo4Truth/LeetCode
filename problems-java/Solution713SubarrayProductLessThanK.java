public class Solution713SubarrayProductLessThanK {

    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;

        int left = 0, right = 0, product = 1, count = 0;
        int n = nums.length;

        while (right < n) {
            product *= nums[right];
            while (product >= k) product /= nums[left++];
            count += 1 + (right - left);
            right++;
        }

        return count;
    }

    public static void main(String[] args) {
        Solution713SubarrayProductLessThanK solution713SubarrayProductLessThanK = new Solution713SubarrayProductLessThanK();

        int[] nums1 = {10, 5, 2, 6};
        int k1 = 100;
        int count1 = solution713SubarrayProductLessThanK.numSubarrayProductLessThanK(nums1, k1);
        System.out.println("count 1: " + count1);

        int[] nums2 = {1, 2, 3};
        int k2 = 0;
        int count2 = solution713SubarrayProductLessThanK.numSubarrayProductLessThanK(nums2, k2);
        System.out.println("count 2: " + count2);
    }

}
