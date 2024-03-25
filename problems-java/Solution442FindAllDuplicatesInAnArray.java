import java.util.ArrayList;
import java.util.List;

public class Solution442FindAllDuplicatesInAnArray {

    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int x = Math.abs(nums[i]);
            if (nums[x - 1] < 0) {
                result.add(x);
            }
            nums[x - 1] *= -1;
        }
        return result;
    }

}
