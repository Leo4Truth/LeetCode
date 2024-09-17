/**
 * @link https://leetcode.cn/problems/distance-between-bus-stops/
 * @level easy
 */
public class Solution1184DistanceBetweenBusStops {

    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int n = distance.length;
        int d1 = 0;
        for (int i = start; i != destination; i = (i + 1) % n) {
            d1 += distance[i];
        }
        int d2 = 0;
        for (int i = destination; i != start; i = (i + 1) % n) {
            d2 += distance[i];
        }
        return d1 < d2 ? d1 : d2;
    }
    
}
