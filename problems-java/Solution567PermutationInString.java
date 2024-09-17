
/**
 * @link https://leetcode.cn/problems/permutation-in-string/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding window
 * @tag 定长滑动窗口
 * @tag fixed length sliding window
 */ 
public class Solution567PermutationInString {
    
    public boolean checkInclusion(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        if (n > m) {
            return false;
        }

        int[] cnt1 = new int[26];
        for (int i = 0; i < 26; i++) {
            cnt1[i] = 0;
        }
        for (int i = 0 ; i < m; i++) {
            cnt1[s1.charAt(i) - 'a']++;
        }

        int[] cnt = new int[26];
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }

        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[s2.charAt(r) - 'a']++;

            if (r - l + 1 > m) {
                cnt[s2.charAt(l) - 'a']--;
                l++;
            }
            
            if (r - l + 1 == m) {
                boolean flag = true;
                // can be optimized
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] != cnt1[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }

        return false;
    }

    /**
     * 优化cnt数组, 只维护一个cnt数组
     * 
     * @param s1
     * @param s2
     * @return
     */
    public boolean checkInclusion1(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < n; ++i) {
            // cnt[i] < 0 means need cnt[i] of 'a' + i
            --cnt[s1.charAt(i) - 'a'];
        }
        int left = 0;
        // 窗口滑动的逻辑与前一种方法不同, 这里窗口滑动直到窗口内的字符串>=s1
        // 退出条件为窗口大小刚好等于s1长度, 此时恰好满足 s2[left, right]是s1的一个组合
        for (int right = 0; right < m; ++right) {
            int x = s2.charAt(right) - 'a';
            ++cnt[x];
            while (cnt[x] > 0) { // 窗口[left, right]内 char 'a' + x 的数量与s1中一致时才会退出这个内层循环
                --cnt[s2.charAt(left) - 'a'];
                ++left;
            }
            if (right - left + 1 == n) {
                return true;
            }
        }
        return false;
    }

}