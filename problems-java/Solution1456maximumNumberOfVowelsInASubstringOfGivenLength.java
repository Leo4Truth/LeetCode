import java.util.Set;
import java.util.HashSet;

/**
 * @link https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * 
 * @difficulty middle
 * 
 * @tag 滑动窗口
 * @tag slide window
 * @tag 定长滑动窗口
 * @tag fixed slide window
 */
public class Solution1456maximumNumberOfVowelsInASubstringOfGivenLength {
    public int maxVowels(String s, int k) {
        Set<Character> vowelChars = new HashSet<>();
        vowelChars.add('a');
        vowelChars.add('e');
        vowelChars.add('i');
        vowelChars.add('o');
        vowelChars.add('u');

        int n = s.length();
        int vowels = 0;
        for (int i = 0; i < k; i++) {
            if (vowelChars.contains(s.charAt(i))) {
                vowels++;
            }
        }

        int maxVowels = vowels;
        for (int r = k; r < n; r++) {
            int l = r - k;
            if (vowelChars.contains(s.charAt(l))) {
                vowels--;
            }
            if (vowelChars.contains(s.charAt(r))) {
                vowels++;
            }
            maxVowels = vowels > maxVowels ? vowels : maxVowels;
        }

        return maxVowels;
    }
}
