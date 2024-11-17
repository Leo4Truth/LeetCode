import java.util.ArrayDeque;

/**
 * @link https://leetcode.cn/problems/longest-well-performing-interval/description/
 * @problem 1124. Longest Well-Performing Interval
 * @level middle
 * 
 * @tag monotonic stack
 * @tag 单调栈
 * @tag prefix sum
 * @tag 前缀和
 */
public class Solution1124 {

    public int longestWPI(int[] hours) {
        int n = hours.length, ans = 0;
        // 前缀和
        var s = new int[n + 1];
        var st = new ArrayDeque<Integer>();
        // s[0]
        st.push(0); 
        for (int j = 1; j <= n; ++j) {
            s[j] = s[j - 1] + (hours[j - 1] > 8 ? 1 : -1);
            if (s[j] < s[st.peek()]) {
                // 感兴趣的 j
                st.push(j);
            }
        }
        for (int i = n; i > 0; --i) {
            while (!st.isEmpty() && s[i] > s[st.peek()]) {
                // [栈顶,i) 可能是最长子数组
                ans = Math.max(ans, i - st.pop()); 
            }
        }
        return ans;
    }

}