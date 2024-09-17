
/**
 * @link https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding window
 * @tag 定长滑动窗口
 * @tag fixed length sliding window
 */ 
public class Solution1888MinimumNumberOfFlipsToMakeTheBinaryStringAlternating {
    
    public int minFlips(String s) {
        int n = s.length();
        String ss = s + s;
        StringBuilder alt1 = new StringBuilder();
        StringBuilder alt2 = new StringBuilder();
        for (int i = 0; i < ss.length(); i++) {
            alt1.append(i % 2 == 0 ? "0" : "1");
            alt2.append(i % 2 == 0 ? "1" : "0");
        }

        int res = ss.length();
        int diff1 = 0;
        int diff2 = 0;
        int l = 0; // left pointer
        // right pointer
        for (int r = 0; r < ss.length(); r++) {
            if (ss.charAt(r) != alt1.charAt(r)) {
                diff1++;
            }
            if (ss.charAt(r) != alt2.charAt(r)) {
                diff2++;
            }

            // remove left end char and add right end char
            if ((r - l + 1) > n) {
                if (ss.charAt(l) != alt1.charAt(l)) {
                    diff1--;
                }
                if (ss.charAt(l) != alt2.charAt(l)) {
                    diff2--;
                }
                l++; // move left pointer
                res = Math.min(res, Math.min(diff1, diff2));
            }
        }

        return res;
    }

}