import java.util.Arrays;

/**
 * @link https://leetcode.cn/problems/minimum-time-to-complete-trips/
 * 
 * @level middle
 * 
 * @tag binary search
 * @tag 二分查找
 */
public class Solution2187MinimumTimeToCompleteTrips {

    public long minimumTime(int[] time, int totalTrips) {
        // 二分查找下界与上界
        long l = 1;
        long r = (long) totalTrips * Arrays.stream(time).max().orElse(0);
        // 二分查找寻找满足要求的最小的 t
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (check(mid, time, totalTrips)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    // 判断 t 时间内是否可以完成 totalTrips 趟旅途
    public boolean check(long t, int[] time, int totalTrips) {
        long cnt = 0;
        for (int period : time) {
            cnt += t / period;
            if (cnt >= totalTrips) {
                return true;
            }
        }
        return false;
    }

}