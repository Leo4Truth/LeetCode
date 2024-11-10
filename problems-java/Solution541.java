/**
 * @link https://leetcode.cn/problems/reverse-string-ii/
 * 
 * @level easy
 */
public class Solution541 {
    public String reverseStr(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            // System.out.println("i: " + i + ", char: " + s.charAt(i));
            if (i % (2 * k) < k - 1) {

            } else if (i % (2 * k) == k - 1) {
                int x = i - k + 1;
                sb.append(rev(s.substring(x, x + k)));
                // System.out.println("reverse: " + x + ", " + (x + k) + ": " + s.substring(x, x + k));
            } else {
                // System.out.println("append: " + i + ": " + s.charAt(i));
                sb.append(s.charAt(i));
            }
            i++;
        }
        if (sb.length() < s.length()) {
            sb.append(rev(s.substring(sb.length(), s.length())));
        }
        return sb.toString();
    }

    private String rev(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution541 solution541 = new Solution541();

        String s1 = "abcdefg";
        int k1 = 2;
        System.out.println("ans1: " + solution541.reverseStr(s1, k1));

        String s2 = "abcd";
        int k2 = 2;
        System.out.println("ans2: " + solution541.reverseStr(s2, k2));

        String s3 = "a";
        int k3 = 2;
        System.out.println("ans3: " + solution541.reverseStr(s3, k3));
    }

}
