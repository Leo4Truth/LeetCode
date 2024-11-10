
import java.util.HashMap;
import java.util.Map;

class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                ans[0] = map.get(target - nums[i]);
                ans[1] = i;
                return ans;
            }
            map.put(nums[i], i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution1 solution1 = new Solution1();
        
        int[] nums1 = {2,7,11,15};
        int target1 = 9;
        System.out.println("ans1: " + solution1.twoSum(nums1, target1));
        
        int[] nums2 = {3,2,4};
        int target2 = 6;
        System.out.println("ans2: " + solution1.twoSum(nums2, target2));
        
        int[] nums3 = {3,3};
        int target3 = 6;
        System.out.println("ans2: " + solution1.twoSum(nums3, target3));


    }
}