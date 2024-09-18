/**
 * @link https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 * 
 * @level middle
 * 
 * @tag 滑动窗口
 * @tag sliding windows
 * @tag 不定长滑动窗口 - 求最长子数组
 */
public class Solution1493LongestSubarrayOf1sAfterDeletingOneElement {

    public int longestSubarray(int[] nums) {
        int l = 0; //表示左指针
        int cnt1 = 0; //表示子数组中1的数量
        int cnt0 = 0; //表示子数组中0的数量
        for (int r = 0; true; r++) {
            cnt0 += 1 - nums[r]; //从右指针为0开始向后遍历，1-nums[r]就是计算0的数量，如果nums[r]为0，cnt0就会加一
            if (cnt0 > 1) { //当0的数量大于1，滑动窗口的左指针就往右滑一下，这时候需要判断丢弃的左指针元素是否为0，为0则把cnt0的数量减一
                cnt0 -= 1 - nums[l++];
            }
            cnt1 = Math.max(cnt1, r - l); //每次遍历完都计算一下数组中1的数量，这里由于是把0去掉，所以直接r-l，不需要r-l+1，然后就是取最大值作为最终的结果，嘻嘻
            // 这里判断下, 提前退出
            if  (r == nums.length - 1) {
                return cnt1;
            }
        }
    }
    
    public int longestSubarray1(int[] nums) {
        int n = nums.length;
        int longest = 0;

        int cnt1 = 0;
        int cnt0 = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt0 += nums[r] == 0 ? 1 : 0;
            cnt1 += nums[r] == 1 ? 1 : 0;
            while (cnt0 > 1) {
                cnt0 -= nums[l] == 0 ? 1 : 0;
                cnt1 -= nums[l] == 1 ? 1 : 0;
                l++;
            }
            int len = cnt1;
            if (cnt0 == 0) {
                len = cnt1 - 1;
            }
            longest = len > longest ? len : longest;
        }

        return longest;
    }
    
    /**
     * 在longestSubarray1的基础上优化, 只记录0的数量cnt, 子数组长度用窗口大小计算
     * 兼容全1和1个0两种情况, 统一在返回时-1
     * @param nums
     * @return
     */
    public int longestSubarray2(int[] nums) {
        int n = nums.length;
        int longest = 0;

        int cnt0 = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt0 += nums[r] == 0 ? 1 : 0;
            while (cnt0 > 1) {
                cnt0 -= nums[l] == 0 ? 1 : 0;
                l++;
            }
            longest = r - l + 1 > longest ? r - l + 1 : longest;
        }

        return longest - 1;
    }

}
