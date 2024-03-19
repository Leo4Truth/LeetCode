import java.util.Arrays;

public class Solution621TaskScheduler {

    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        Arrays.sort(freq);
        int chunk = freq[25] - 1;
        int idle = chunk * n;

        for (int i = 24; i >= 0; i--) {
            idle -= Math.min(chunk, freq[i]);
        }

        return idle < 0 ? tasks.length : tasks.length + idle;
    }

    public static void main(String[] args) {
        Solution621TaskScheduler solution = new Solution621TaskScheduler();
//        char[] tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
        char[] tasks = {'A','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int minimumIntervals = solution.leastInterval(tasks, 29);
        System.out.println(minimumIntervals);
    }
}
