package com.leetcode;

import org.junit.jupiter.api.Test;

public class Test215 {

    @Test
    public void test1() {
        /**
         * Test for max heap solution
         */
        Solution215 solution = new Solution215();
        int[] nums = {1, 2, 3, 4, 5};
        int k = 3;
        int res = solution.findKthLargest_maxHeap(nums, k);
        assert(res == 3);
        System.out.println(res);
    }
    
    @Test
    public void test2() {
        /**
         * Test for quick select solution
         */
        Solution215 solution = new Solution215();
        int[] nums = {1, 2, 3, 4, 5};
        int k = 3;
        int res = solution.findKthLargest_quickSelect(nums, k);
        assert(res == 3);
        System.out.println(res);
    }
}
