
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @link https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
 * 
 * @level middle
 */
public class Solution49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            String key = getCharCntStr(getCharCnt(str));
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }
            map.get(key).add(str);
        }
        return new ArrayList<>(map.values());
    }

    private int[] getCharCnt(String s) {
        int[] charCnt = new int[26];
        if (s == null || s.isEmpty() || s.isBlank()) {
            return charCnt;
        }
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            charCnt[ch - 'a']++;
        }
        return charCnt;
    }

    private String getCharCntStr(int[] charCnt) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            sb.append((char) ('a' + i)).append(String.valueOf(charCnt[i]));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution49 solution49 = new Solution49();
        
        String[] strs1 = {"eat","tea","tan","ate","nat","bat"};
        List<List<String>> ans1 = solution49.groupAnagrams(strs1);
        System.out.println("[");
        for (int i = 0; i < ans1.size(); i++) {
            System.out.print("\t[");
            for (int j = 0; j < ans1.get(i).size(); j++) {
                System.out.print("\"" + ans1.get(i).get(j) + "\"");
                if (j != ans1.get(i).size() - 1) {
                    System.out.print(",");
                }
            }
            System.out.println("]");
        }
        System.out.println("]");
    }
}