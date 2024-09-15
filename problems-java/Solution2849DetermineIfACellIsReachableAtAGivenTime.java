public class Solution2849DetermineIfACellIsReachableAtAGivenTime {
    
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = sx - fx;
        int dy = sy - fy;

        if (dx == 0 && dy == 0) {
            return t > 1;
        }

        dx = dx >= 0 ? dx : -dx;
        dy = dy >= 0 ? dy : -dy;

        int minSteps = dx > dy ? dx : dy;

        return minSteps <= t;
    }
    
}
