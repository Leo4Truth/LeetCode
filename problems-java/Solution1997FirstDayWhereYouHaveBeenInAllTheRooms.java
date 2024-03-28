import java.util.HashSet;
import java.util.Set;

public class Solution1997FirstDayWhereYouHaveBeenInAllTheRooms {

    private static final int MOD = 1000000007;

    public int firstDayBeenInAllRoomsSim(int[] nextVisit) {
        int n = nextVisit.length;
        int[] visitCount = new int[n];
        Set<Integer> visited = new HashSet<>();

        int day = 0;
        int i = 0;
        visited.add(0);
        visitCount[0] = 1;
        while (true) {
            day++;
            i = (visitCount[i] % 2 == 1) ? nextVisit[i] : ((i + 1) % n);
//            System.out.println("day: " + day + ", visit: " + i);
            visited.add(i);
            visitCount[i]++;
            if (visited.size() == n) {
                break;
            }
        }
        return day;
    }

    /**
     * 动态规划
     *
     * 关键在于: 0 <= nextVisit[i] <= i
     * 而只有访问过该房间偶数次时才会到达下一个房间，进而推断出到达 i 时，[0,i) 的房间已经被访问过偶数次。
     *
     * @param nextVisit
     * @return
     */
    public int firstDayBeenInAllRooms(int[] nextVisit) {
        int n = nextVisit.length;
        int[] dp = new int[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nextVisit[i - 1] == i - 1) {
                dp[i] = (dp[i - 1] + 2) % MOD;
            } else {
                int next = nextVisit[i - 1];
                dp[i] = (((dp[i - 1] + 1) * 2) % MOD + MOD - dp[next]) % MOD;
            }
        }
        return dp[n - 1];
    }

    public static void main(String[] args) {
        Solution1997FirstDayWhereYouHaveBeenInAllTheRooms solution1997FirstDayWhereYouHaveBeenInAllTheRooms =
                new Solution1997FirstDayWhereYouHaveBeenInAllTheRooms();
        int[] nextVisit1 = {0, 0};
        System.out.println(solution1997FirstDayWhereYouHaveBeenInAllTheRooms.firstDayBeenInAllRooms(nextVisit1));

        int[] nextVisit2 = {0, 0, 2};
        System.out.println(solution1997FirstDayWhereYouHaveBeenInAllTheRooms.firstDayBeenInAllRooms(nextVisit2));

        int[] nextVisit3 = {0, 1, 2, 0};
        System.out.println(solution1997FirstDayWhereYouHaveBeenInAllTheRooms.firstDayBeenInAllRooms(nextVisit3));
    }

}
