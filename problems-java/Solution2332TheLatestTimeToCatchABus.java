import java.util.Arrays;

/**
 * @link https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/description/
 * 
 * @level middle
 * 
 * @tag
 */
public class Solution2332TheLatestTimeToCatchABus {

    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        int pos = 0;
        int space = 0;

        for (int arrive : buses) {
            space = capacity;
            while (space > 0 && pos < passengers.length && passengers[pos] <= arrive) {
                space--;
                pos++;
            }
        }

        pos--;
        int lastCatchTime = space > 0 ? buses[buses.length - 1] : passengers[pos];
        while (pos >= 0 && passengers[pos] == lastCatchTime) {
            pos--;
            lastCatchTime--;
        }

        return lastCatchTime;
    }

}
