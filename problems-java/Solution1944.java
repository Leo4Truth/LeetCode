import java.util.LinkedList;

/**
 * @link https://leetcode.cn/problems/number-of-visible-people-in-a-queue/description/
 * 
 * @level difficult
 * 
 * @tag monotonic stack
 */
public class Solution1944 {

    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        int[] res = new int[n];
        LinkedList<Integer> stk = new LinkedList<>();
        for (int i = n - 1; i >= 0; i--) {
            res[i] = 0;
            for (Integer h : stk) {
                res[i]++;
                if (heights[i] <= h) {
                    break;
                }
            }
            while (!stk.isEmpty() && stk.peek() < heights[i]) {
                stk.poll();
            }
            stk.push(heights[i]);
        }
        return res;
    }

    /**
     * faster
     */
    public int[] canSeePersonsCount1(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        LinkedList<Integer> stk = new LinkedList<>();
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = 0;
            while (!stk.isEmpty() && stk.peek() < heights[i]) {
                // 第i个人能看到的比ta矮或者一样高的人 == 被第i个人挡住的人
                stk.poll();
                ans[i]++;
            }
            // 还可以再看到1个人
            if (!stk.isEmpty()) {
                ans[i]++;
            }
            stk.push(heights[i]);
        }
        return ans;
    }

    /**
     * fastest
     * stack implemented by array
     */
    public int[] canSeePersonsCount2(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        int[] st = new int[n];
        int top = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && st[top] < heights[i]) {
                top--;
                ans[i]++;
            }
            if (top >= 0) { // 还可以再看到一个人
                ans[i]++;
            }
            st[++top] = heights[i];
        }
        return ans;
    }

}