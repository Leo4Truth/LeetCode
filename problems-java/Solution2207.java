import java.util.List;
import java.util.ArrayList;

/**
 * @link https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/description/
 * 
 * @level middle
 * 
 */
public class Solution2207 {
    public long maximumSubsequenceCount(String text, String pattern) {
        long res = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < text.length(); ++i) {
            if (text.charAt(i) == pattern.charAt(1)) {
                res += cnt1;
                cnt2++;
            }
            if (text.charAt(i) == pattern.charAt(0)) {
                cnt1++;
            }
        }
        return res + Math.max(cnt1, cnt2);
    }
}
