/*
 * @lc app=leetcode.cn id=658 lang=java
 *
 * [658] 找到 K 个最接近的元素
 */

import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int l = 0, r = arr.length - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // 以l作为起始索引，长度为k
        List<Integer> res = new ArrayList<>(k);
        for (int i = 0; i < k; i++) {
            res.add(arr[i + l]);
        }
        return res;

    }
}
// @lc code=end
