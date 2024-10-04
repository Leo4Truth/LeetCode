import java.util.LinkedList;

/**
 * @link https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/
 * 
 * @level difficult
 * 
 * @tag monotonic stack
 * @tag 单调栈
 */
public class Solution3113FindTheNumberOfSubarraysWhereBoundaryElementsAreMaximum {

    public long numberOfSubarrays(int[] nums) {
        LinkedList<int[]> stk = new LinkedList<>();

        long res = nums.length;
        stk.push(new int[]{Integer.MAX_VALUE, 0}); // 无穷大哨兵
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] > stk.peek()[0]) {
                stk.pop();
            }
            if (nums[i] == stk.peek()[0]) {
                res += stk.peek()[1]++;
            } else {
                stk.push(new int[]{nums[i], 1});
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,4,3,3,2};

        Solution3113FindTheNumberOfSubarraysWhereBoundaryElementsAreMaximum solution = 
            new Solution3113FindTheNumberOfSubarraysWhereBoundaryElementsAreMaximum();
        
            System.out.println(solution.numberOfSubarrays(nums));
    }
    
}