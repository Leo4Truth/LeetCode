import java.util.Set;
import java.util.HashSet;

/**
 * @link https://leetcode.cn/problems/count-complete-substrings/description/
 * 
 * @level hard
 * 
 * @tag 滑动窗口
 * @tag sliding window
 * @tag 定长滑动窗口
 * @tag fixed length sliding window
 */ 
public class Solution2953CountCompleteSubstrings {
    
    public int countCompleteSubstrings(String word, int k) {
        int n = word.length();

        // 统计总共出现了多少个不同的字母, 记为w
        Set<Character> charSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            charSet.add(word.charAt(i));
        }

        int res = 0;

        // 根据charSet的大小w, 使用 w, 2*w, .., k*w 的定长滑动窗口去寻找符合要求的substring, 并计数
        for (int i = 1; i <= charSet.size(); i++) {
            int windowSize = i * k;

            int[] cnt = new int[26];
            int l = 0;
            for (int r = 0; r < n; r++) {
                cnt[word.charAt(r) - 'a']++;
                if (r - l + 1 > windowSize) {
                    cnt[word.charAt(l) - 'a']--;
                    l++;
                    // l移动到无法满足滑动窗口size的时候就提前退出
                    if (n - l + 1 < windowSize) {
                        break;
                    }
                }

                // 这里判断条件2, 即相邻字符之间diff<=2, 已在滑动窗口内的保证满足, 对于新加入的字符(r处), 如果不满足, 直接将l移动到r处
                if (r > 0 && l <= r - 1) {
                    int diff = word.charAt(r) - word.charAt(r - 1);
                    diff = diff < 0 ? -diff : diff;
                    if (diff > 2) {
                        for (int j = l; j < r; j++) {
                            cnt[word.charAt(j) - 'a']--;
                        }
                        l = r;
                        // 这里也可以提前结束本轮循环
                        continue;
                    }
                }
                
                // 判断当前滑动窗口内的字符串是否满足要求
                if (r - l + 1 == windowSize) {
                    boolean flag = true;
                    for (int j = 0; j < 26; j++) {
                        if (cnt[j] != 0 && cnt[j] != k) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        res++;
                    }
                }
            }
        }

        return res;
    }

}