import java.util.Arrays;
import java.util.stream.IntStream;

/*
 * @lc app=leetcode.cn id=698 lang=java
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
    private int[] nums;
    private boolean[] used;
    private int avg;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = IntStream.of(nums).sum();
        if (sum % k != 0) {
            return false;
        }
        avg = sum / k;

        Arrays.sort(nums);
        this.nums = nums;
        used = new boolean[nums.length];
        Arrays.fill(used, false);
        return search(nums.length, avg, k);
    }

    private boolean search(int start, int target, int k) {
        if (k == 0)
            return true;
        if (target == 0)
            return search(nums.length, avg, k - 1);
        for (int i = start - 1; i >= 0; i--) {
            if (!used[i]) {
                used[i] = true;
                if (nums[i] <= target && search(i, target - nums[i], k))
                    return true;
                used[i] = false;
            }
        }
        return false;
    }
}
// @lc code=end
