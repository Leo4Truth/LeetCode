public class Solution41FirstMissingPositive {

    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 0, 3, 5, 4, -1, 6, 8};
        int[] nums2 = {3, 4, -1, 1};
        Solution41FirstMissingPositive solution41FirstMissingPositive = new Solution41FirstMissingPositive();
        int missing1 = solution41FirstMissingPositive.firstMissingPositive(nums1);
        System.out.println(missing1);
        int missing2 = solution41FirstMissingPositive.firstMissingPositive(nums2);
        System.out.println(missing2);
    }

}
