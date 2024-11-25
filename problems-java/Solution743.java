import java.util.AbstractMap;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @link https://leetcode.cn/problems/network-delay-time/description/
 */
public class Solution743 {
    
    /**
     * bfs限制距离, 超时
     * @param times
     * @param n
     * @param k
     * @return
     */
    public int networkDelayTime1(int[][] times, int n, int k) {
        int ans = 0;
        int graph[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = -1;
            }
        }
        for (int[] time : times) {
            graph[time[0] - 1][time[1] - 1] = time[2];
        }
        int delays[] = new int[n];
        for (int i = 0; i < n; i++) {
            delays[i] = -1;
        }
        delays[k - 1] = 0;
        Stack<int[]> stk = new Stack<>();
        stk.push(new int[] {k - 1, 0});
        while (!stk.isEmpty()) {
            int[] entry = stk.pop();
            int current = entry[0];
            int depth = entry[1];
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (graph[current][neighbor] == -1) {
                    continue;
                } else {
                    if (depth + 1 < n - 1) {
                        stk.push(new int[] {neighbor, depth + 1});
                    }
                    if (delays[neighbor] == -1 || delays[neighbor] > delays[current] + graph[current][neighbor]) {
                        delays[neighbor] = delays[current] + graph[current][neighbor];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (delays[i] == -1) {
                ans = -1;
                break;
            }
            ans = delays[i] > ans ? delays[i] : ans;
        }
        return ans;
    }

    /**
     * dijkstra
     * @param times
     * @param n
     * @param k
     * @return
     */
    public int networkDelayTime2(int[][] times, int n, int k) {
        final int INF = Integer.MAX_VALUE / 2;
        List<int[]>[] g = new List[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<int[]>();
        }
        for (int[] t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].add(new int[]{y, t[2]});
        }

        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[k - 1] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        pq.offer(new int[]{0, k - 1});
        while (!pq.isEmpty()) {
            int[] p = pq.poll();
            int time = p[0], x = p[1];
            if (dist[x] < time) {
                continue;
            }
            for (int[] e : g[x]) {
                int y = e[0], d = dist[x] + e[1];
                if (d < dist[y]) {
                    dist[y] = d;
                    pq.offer(new int[]{d, y});
                }
            }
        }

        int ans = Arrays.stream(dist).max().getAsInt();
        return ans == INF ? -1 : ans;
    }

    public static void main(String[] args) {
        Solution743 solution743 = new Solution743();

        int[][] times1 = {
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
        };
        int n1 = 4;
        int k1 = 2;
        System.out.println("1 ans1: " + solution743.networkDelayTime1(times1, n1, k1));
        System.out.println("2 ans1: " + solution743.networkDelayTime2(times1, n1, k1));
        
        int[][] times2 = {
            {1, 2, 1}
        };
        int n2 = 2;
        int k2 = 1;
        System.out.println("2 ans2: " + solution743.networkDelayTime1(times2, n2, k2));
        System.out.println("2 ans2: " + solution743.networkDelayTime2(times2, n2, k2));
        
        int[][] times3 = {
            {1, 2, 1}
        };
        int n3 = 2;
        int k3 = 2;
        System.out.println("3 ans3: " + solution743.networkDelayTime1(times3, n3, k3));
        System.out.println("3 ans3: " + solution743.networkDelayTime2(times3, n3, k3));
        
        // 有环
        int[][] times4 = {
            {1, 2, 1},
            {2, 1, 3}
        };
        int n4 = 2;
        int k4 = 2;
        System.out.println("4 ans4: " + solution743.networkDelayTime1(times4, n4, k4));
        System.out.println("4 ans4: " + solution743.networkDelayTime2(times4, n4, k4));
    }

}