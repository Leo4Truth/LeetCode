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
        // 所有元素自身组成的subarray肯定满足要求, 因此res初始为nums.length
        long res = nums.length;
        // 这里维护单调栈, 元素为 {数字, 出现次数}, 以数字大小为序, 单调递减(底大顶小)
        LinkedList<int[]> stk = new LinkedList<>();
        stk.push(new int[]{Integer.MAX_VALUE, 0}); // 无穷大哨兵
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] > stk.peek()[0]) {
                stk.pop();
            }
            // 当前数字nums[i] == stk.peek()[0]时, 以nums[i]为首尾且最大的子数组可以构造出stk.peek()[1]个
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