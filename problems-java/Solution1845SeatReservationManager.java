import java.util.PriorityQueue;

public class Solution1845SeatReservationManager {

    /**
     * Your SeatManager object will be instantiated and called as such:
     * SeatManager obj = new SeatManager(n);
     * int param_1 = obj.reserve();
     * obj.unreserve(seatNumber);
     */
    public static void main(String[] args) {
        int n = Integer.valueOf(args[0]);
        SeatManager obj = new SeatManager(n);
        int param_1 = obj.reserve();
        obj.reserve();
        obj.unreserve(1);
    }


    public static class SeatManager {

        private final PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        public SeatManager(int n) {
            for (int i = 1; i <= n; i++) {
                pq.add(i);
            }
        }
        
        public int reserve() {
            if (pq.isEmpty()) {
                return 0;
            }
            else {
                return pq.poll();
            }
        }
        
        public void unreserve(int seatNumber) {
            pq.add(seatNumber);
        }
    }
    
    
}
