public class Solution1793MaximumScoreOfAGoodSubarray {
    public int maximumScore(int[] nums, int k) {
        int len = nums.length;
        int i = k;
        int j = k;
        int maxScore = Integer.MIN_VALUE;
        int min = nums[k];
        while (i >= 0 && j < len) {
//            System.out.println(i + "," + j);
            int score = min * (j - i + 1);
            if (score > maxScore) {
                maxScore = score;
            }
            if (i > 0 && j < len - 1) {
                if (nums[i - 1] <= nums[j + 1]) {
                    j++;
                    min = Math.min(nums[j], min);
                } else {
                    i--;
                    min = Math.min(nums[i], min);
                }
            } else if (i > 0 && j == len - 1) {
                i--;
                min = Math.min(nums[i], min);
            } else if (i == 0 && j < len - 1) {
                j++;
                min = Math.min(nums[j], min);
            } else {
                i--;
                j++;
            }
        }
        return maxScore;
    }

    public static void main(String[] args) {
        Solution1793MaximumScoreOfAGoodSubarray solution = new Solution1793MaximumScoreOfAGoodSubarray();

        int[] nums = {1, 4, 3, 7, 4, 5};
        int maxScore = solution.maximumScore(nums, 3);
        System.out.println(maxScore);
    }
}
