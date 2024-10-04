public class Solution1227AirplaneSeatAssignmentProbability {

    public double nthPersonGetsNthSeat(int n) {
        if (n == 1) {
            return 1.0;
        }
        return 0.5;
    }

    public static void main(String[] args) {
        int n;
        Solution1227AirplaneSeatAssignmentProbability solution = new Solution1227AirplaneSeatAssignmentProbability();
        double p = solution.nthPersonGetsNthSeat(n);
        System.out.print("n: {}, probability: {}", n, p);
    }

}