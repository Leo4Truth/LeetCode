import java.util.*;
import java.util.Map.Entry;

/**
 * @link https://leetcode.cn/problems/naming-a-company/
 * 
 * @level hard
 */
public class Solution2306NamingACompany {
    public long distinctNames(String[] ideas) {
        Map<Character, Set<String>> firstCharMap = new HashMap<>();
        for (String idea : ideas) {
            char firstChar = idea.charAt(0);
            String suffix = idea.substring(1);
            firstCharMap.putIfAbsent(firstChar, new HashSet<>());
            firstCharMap.get(firstChar).add(suffix);
        }

        long ans = 0;
        for (Map.Entry<Character, Set<String>> entryA : firstCharMap.entrySet()) {
            char preA = entryA.getKey();
            Set<String> setA = entryA.getValue();
            for (Map.Entry<Character, Set<String>> entryB : firstCharMap.entrySet()) {
                char preB = entryB.getKey();
                Set<String> setB = entryB.getValue();
                if (preA == preB) {
                    continue;
                }
                int intersect = getIntersectSize(setA, setB);
                ans += (long) (setA.size() - intersect) * (setB.size() - intersect);
            }
        }
        return ans;
    }

    public int getIntersectSize(Set<String> a, Set<String> b) {
        int ans = 0;
        for (String s : a) {
            if (b.contains(s)) {
                ans++;
            }
        }
        return ans;
    }
}
