import java.util.Arrays;

public class Solution2580CountWaysToGroupOverlappingRanges {

    static final int MOD = 1000000007;

    /**
     * offical
     * @param ranges
     * @return
     */
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int n = ranges.length;
        int res = 1;
        for (int i = 0; i < n; ) {
            int r = ranges[i][1];
            int j = i + 1;
            while (j < n && ranges[j][0] <= r) {
                r = Math.max(r, ranges[j][1]);
                j++;
            }
            res = res * 2 % MOD;
            i = j;
        }
        return res;
    }

    private boolean isOverlap(int[] a, int[] b) {
        return !(a[1] < b[0]);
    }

}
