/**
 * @linkhttps://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/
 * 
 * @level easy
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution3090MaximumLengthSubstringWithTwoOccurrences {

    public int maximumLengthSubstring(String s) {
        int n = s.length();

        int[] cnt = new int[26];
        
        int max = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            int x = s.charAt(r) - 'a';
            cnt[x]++;
            while (cnt[x] > 2) {
                int y = s.charAt(l) - 'a';
                cnt[y]--;
                l++;
                if (x == y) {
                    break;
                }
            }
            max = r - l + 1 > max ? r - l + 1 : max;
        }

        return max;
    }

}
