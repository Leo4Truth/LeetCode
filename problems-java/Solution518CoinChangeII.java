public class Solution518CoinChangeII {

    private int result = 0;

    /**
     * 动态规划 - 一维
     * dp[i] 表示总值为 i 的硬币组合数
     * @param amount
     * @param coins
     * @return
     */
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            /**
             * 默认 coins 从小到大已排序
             * 对于硬币 coin, 考虑 [coin, amount] 范围内，只用 coin 和比 coin 面值小的硬币组合
             * 例如: amount = 5, coins = [1, 2, 5]
             * 外循环1: coin = 1
             * 内循环1: i = [1, 2, 3, 4, 5]
             * 内循环1结束后, 得到仅用 coin = 1 , amount = [1, 2, 3, 4, 5] 的组合数
             * 外循环2: coin = 2
             * 内循环2: i = [2, 3, 4, 5]
             * dp[2] = dp[2] + dp[2 - 2] = dp[2] + dp[0],
             *  原 dp[2] 表示仅用 coin = 1 的情况下, amount = 2 的组合数
             *  dp[2 - 2] 表示从对总数为 2 的组合, 用 1 个面值为 2 的硬币代替
             * 内循环2结束后, 得到仅用 coin = [1, 2] , amount = [2, 3, 4, 5] 的组合数
             */
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }

    /**
     * DFS方法, 递归, 会超时
     * @param amount
     * @param coins
     * @return
     */
    public int changeDfs(int amount, int[] coins) {
        int n = coins.length;
        int[] count = new int[n];
        dfs(amount, coins, count, n - 1);
        return result;
    }

    private void dfs(int amount, int[] coins, int[] count, int max) {
        if (amount == 0) {
            result++;
            return;
        }
        int n = coins.length;
        for (int i = max; i >= 0; i--) {
            int coin = coins[i];
            if (amount >= coins[i]) {
                for (int v = coin; v <= amount; v += coin) {
                    count[i] = v / coin;
                    dfs(amount - v, coins, count, i - 1);
                    count[i] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        int amount = 5;
        int[] coins = {1, 2, 5};
        Solution518CoinChangeII solution518CoinChangeII = new Solution518CoinChangeII();
        int result = solution518CoinChangeII.change(amount, coins);
        System.out.println(result);

        case14();
    }

    private static void case14() {
        int amount = 500;
        int[] coins = {3,5,7,8,9,10,11};
        Solution518CoinChangeII solution518CoinChangeII = new Solution518CoinChangeII();
        int result = solution518CoinChangeII.change(amount, coins);
        System.out.println(result);
    }

}
