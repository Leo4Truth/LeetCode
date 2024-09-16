import java.util.Set;
import java.util.HashSet;

/**
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=problem-list-v2&envId=7NLUuUun
 * 
 * @level middle
 * 
 * 
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

}
