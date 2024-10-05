import java.util.*;

/**
 * @link https://leetcode.cn/problems/132-pattern/description/
 * @name 456. 132 Pattern
 * @level middle
 * 
 * @tag monotonic stack
 * @tag 单调栈
 */
public class Solution456 {

    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return false;
        }
        // 反向遍历, 单调递增, 元素为数字
        LinkedList<Integer> stk = new LinkedList<>();
        // numk记录所有出栈元素中的最大值, 132pattern(nums[i],nums[j],nums[k])中的nums[k]
        int numk = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < numk) {
                return true;
            }
            // 栈顶元素比当前元素小时, 栈顶元素出栈, 更新维护numk
            while (!stk.isEmpty() && stk.peek() < nums[i]) {
                numk = Math.max(numk, stk.poll()); 
            }
            stk.push(nums[i]);
        }
        return false;
    }

}