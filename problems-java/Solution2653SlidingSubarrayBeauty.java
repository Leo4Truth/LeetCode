import java.util.List;
import java.util.ListIterator;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * @link https://leetcode.cn/problems/sliding-subarray-beauty/description/
 * 
 * @level middle
 * 
 * 
 */
public class Solution2653SlidingSubarrayBeauty {

    /**
     * 如果使用List维护负整数列表, 会超时
     * 
     * @param nums
     * @param k
     * @param x
     * @return
     */
    public int[] getSubarrayBeauty(int[] nums, int k, int x) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        
        List<Integer> negativeIntegerList = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                int j = 0;
                for (; j < negativeIntegerList.size(); j++) {
                    if (negativeIntegerList.get(j) >= nums[i]) {
                        break;
                    }
                }
                System.out.println("insert " + String.valueOf(nums[i]) + " at index: " + String.valueOf(j));
                negativeIntegerList.add(j, nums[i]);
            }
        }

        result[0] = negativeIntegerList.size() >= x ? negativeIntegerList.get(x - 1) : 0;

        for (int r = k; r < n; r++) {
            int l = r - k;
            if (nums[l] < 0) {
                int j = 0;
                for (; j < negativeIntegerList.size(); j++) {
                    if (negativeIntegerList.get(j) == nums[l]) {
                        break;
                    }
                }
                negativeIntegerList.remove(j);
            }
            if (nums[r] < 0) {
                boolean inserted = false;
                for (int j = 0; j < negativeIntegerList.size(); j++) {
                    if (negativeIntegerList.get(j) >= nums[r]) {
                        negativeIntegerList.add(j, nums[r]);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    negativeIntegerList.add(negativeIntegerList.size(), nums[r]);
                }
            }

            result[r - k + 1] = negativeIntegerList.size() >= x ? negativeIntegerList.get(x - 1) : 0;
        }

        return result;
    }

    /**
     * 改用桶计数维护负整数列表
     * 桶大小由 提示: -50 <= nums[i] <= 50 决定
     * 
     * @param nums
     * @param k
     * @param x
     * @return
     */
    public int[] getSubarrayBeauty1(int[] nums, int k, int x) {
        int BIAS = 50;
        int n = nums.length;
        int[] result = new int[n - k + 1];
        int[] count = new int[BIAS * 2 + 1];
        for (int i = 0; i < count.length; i++) {
            count[i] = 0;
        }

        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                count[nums[i] + BIAS]++;
            }
        }
        
        int xx = 0;
        for (int nega = 0; nega < count.length; nega++) {
            xx += count[nega];
            if (xx >= x) {
                result[0] = nega - BIAS;
            }
        }

        for (int r = k; r < n; r++) {
            int l = r - k;
            if (nums[l] < 0) {
                count[nums[l] + BIAS]--;
            }
            if (nums[r] < 0) {
                count[nums[r] + BIAS]++;
            }

            xx = 0;
            for (int nega = 0; nega < count.length; nega++) {
                xx += count[nega];
                if (xx >= x) {
                    result[r - k + 1] = nega - BIAS;
                }
            }
        }

        return result;
    }

}
