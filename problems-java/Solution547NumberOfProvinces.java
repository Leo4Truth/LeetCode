/**
 * @link https://leetcode.cn/problems/number-of-provinces/description/
 * 
 * @level middle
 * 
 * @tag graph
 * @tag dfs 深度优先搜索
 * @tag bfs 广度优先搜索
 * @tag union set 并查集
 * @tag 图论
 * @tag 
 */
public class Solution547NumberOfProvinces {

    public int findCircleNum(int[][] isConnected) {
        int cities = isConnected.length;
        boolean[] visited = new boolean[cities];
        int provinces = 0;
        for (int i = 0; i < cities; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, cities, i);
                provinces++;
            }
        }
        return provinces;
    }

    public void dfs(int[][] isConnected, boolean[] visited, int cities, int i) {
        for (int j = 0; j < cities; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, cities, j);
            }
        }
    }

}
