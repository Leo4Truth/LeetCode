import java.util.Set;
import java.util.HashSet;

/**
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=7NLUuUun
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution3LongestSubstringWithoutRepeatingCharacters {

    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty()) {
            return 0;
        }
        Set<Character> charSet = new HashSet<>();
        int longest = 0;
        int r = 0;
        for (int l = -1; l < s.length(); l++) {
            if (l >= 0) {
                charSet.remove(s.charAt(l));
            }
            while (!charSet.contains(s.charAt(r))) {
                charSet.add(s.charAt(r));
                r++;
                if (r == s.length()) {
                    break;
                }
            }
            longest = r - l - 1 > longest ? r - l - 1 : longest;
            if (r == s.length()) {
                break;
            }
        }
        return longest;
    }

    public int lengthOfLongestSubstring1(String s) {
        int n = s.length();
        if (s.isEmpty()) {
            return 0;
        }
        Set<Character> charSet = new HashSet<>();
        int longest = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (!charSet.contains(s.charAt(r))) {
                charSet.add(s.charAt(r));
                longest = charSet.size() > longest ? charSet.size() : longest;
            } else {
                while (s.charAt(l) != s.charAt(r)) {
                    charSet.remove(s.charAt(l));
                    l++;
                }
                // 这里不需要再remove了, 但是左指针要移动
                l++;
            }
        }
        return longest;
    }

}
