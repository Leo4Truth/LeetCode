import java.util.*;

/**
 * @link https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/
 * @level difficult
 * 
 * @tag monotonic stack
 * @tag 单调栈
 */
public class Solution3113 {

    /**
     * O(n^2) 超时, 883/890
     * @return
     */
    public long numberOfSubarrays1(int[] nums) {
        int len = nums.length;
        int cnt = len;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] > nums[i]) {
                    break;
                } else {
                    if (nums[i] == nums[j]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    /**
     * 单调栈
     * 
     * 0. 开始ans = nums.length, 表示每个元素本身组成的subarray都符合条件
     * 1. 底大顶小, 入栈元素为 {数字, 及其出现次数}, 比较元素大小时, 按数字大小比较
     * 2. 从左向右遍历nums数组
     * 3. if nums[i] > stk.peek()[0], stk.pop()直到stk.peek()[0] <= nums[i]
     * 4. if nums[i] == stk.peek()[0], ans += stk.peek()[0], stk.peek()[1]++
     * 5. if nums[i] < stk.peek()[0], stk.push({nums[i], 1})
     * 6. return ans
     */
    public long numberOfSubarrays2(int[] nums) {
        long ans = nums.length;
        Deque<int[]> st = new ArrayDeque<>();
        st.push(new int[]{Integer.MAX_VALUE, 0}); // 无穷大哨兵
        for (int x : nums) {
            while (x > st.peek()[0]) {
                st.pop();
            }
            if (x == st.peek()[0]) {
                ans += st.peek()[1]++;
            } else {
                st.push(new int[]{x, 1});
            }
        }
        return ans;
    }

}
