public class Solution1227AirplaneSeatAssignmentProbability {

    public double nthPersonGetsNthSeat(int n) {
        if (n == 1) {
            return 1.0;
        }
        return 0.5;
    }

    public static void main(String[] args) {
        int n = 5;
        Solution1227AirplaneSeatAssignmentProbability solution = new Solution1227AirplaneSeatAssignmentProbability();
        double p = solution.nthPersonGetsNthSeat(n);
        System.out.println("n: " + n + ", probability: " + p);
    }

}