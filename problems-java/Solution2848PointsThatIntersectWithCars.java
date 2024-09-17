import java.util.HashMap;
import java.util.List;
import java.util.Map;


/**
 * @author liuyuwen
 */
public class Solution2848PointsThatIntersectWithCars {

    public int numberOfPoints(List<List<Integer>> nums) {
        int n = nums.size();
        Map<Integer, Integer> countMap = new  HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int ii = nums.get(i).get(0); ii <= nums.get(i).get(1); ii++) {
                if (!countMap.containsKey(ii)) {
                    countMap.put(ii, 0);
                }
                countMap.put(ii, countMap.get(ii) + 1);
            }
        }
        return countMap.keySet().size();
    }
    
    public int numberOfPoints2(List<List<Integer>> nums) {
        int[] map = new int[100];
        for (int i = 0; i < 100; i++) {
            map[i] = 0;
        }
        int max = 0;
        for (List<Integer> se : nums) {
            for (int i = se.get(0) - 1; i < se.get(1); i++) {
                map[i] = 1;
            }
            max = se.get(1) > max ? se.get(1) : max;
        }
        int intersectCount = 0;
        for (int i = 0; i <= max - 1; i++) {
            intersectCount += (map[i] == 1 ? 1 : 0);
        }
        return intersectCount;
    }
    
    /**
     * 差分
     * 时间复杂度: O(n + C)
     * 空间复杂度: O(n)
     * 
     * 
     * @param nums
     * @return
     */
    public int numberOfPoints3(List<List<Integer>> nums) {
        int C = 0;
        for (List<Integer> interval : nums) {
            C = Math.max(C, interval.get(1));
        }

        int[] diff = new int[C + 2];
        for (List<Integer> interval : nums) {
            ++diff[interval.get(0)];
            --diff[interval.get(1) + 1];
        }

        int ans = 0, count = 0;
        for (int i = 1; i <= C; ++i) {
            count += diff[i];
            if (count > 0) {
                ++ans;
            }
        }
        return ans;
    }

}
