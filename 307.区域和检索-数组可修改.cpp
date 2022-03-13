/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include "common.hpp"
#include <memory>

// @lc code=start
template <typename InputIt>
class IntervalTree {
public:
    using value_type = typename std::iterator_traits<InputIt>::value_type;

private:
    value_type data;
    InputIt    left, right;

    std::unique_ptr<IntervalTree> lchild, rchild;

public:
    IntervalTree(InputIt first, InputIt last) : left(first), right(last) {
        assert(std::distance(left, right) > 0);
        if (std::distance(left, right) == 1) {
            data = *left;
        } else {
            auto mid = std::next(left, std::distance(left, right) / 2);
            lchild   = std::make_unique<IntervalTree>(left, mid);
            rchild   = std::make_unique<IntervalTree>(mid, right);
            data     = lchild->data + rchild->data;
        }
    }

    value_type update(InputIt idx, value_type val) {
        assert(std::distance(left, idx) >= 0);
        assert(std::distance(idx, right) > 0);
        if (std::distance(left, right) == 1) {
            data = val;
        } else {
            auto mid = std::next(left, std::distance(left, right) / 2);
            if (std::distance(left, idx) < std::distance(left, mid)) {
                data = lchild->update(idx, val) + rchild->data;
            } else {
                data = rchild->update(idx, val) + lchild->data;
            }
        }
        return data;
    }

    value_type sumRange(InputIt begin, InputIt end) {
        assert(std::distance(left, begin) >= 0);
        assert(std::distance(end, right) >= 0);
        assert(std::distance(begin, end) >= 0);
        if (begin == end) {
            return value_type{};
        }
        if (begin == left && end == right) {
            return data;
        }
        auto mid = std::next(left, std::distance(left, right) / 2);
        if (std::distance(left, end) <= std::distance(left, mid)) {
            return lchild->sumRange(begin, end);
        }
        if (std::distance(left, mid) <= std::distance(left, begin)) {
            return rchild->sumRange(begin, end);
        }
        return lchild->sumRange(begin, mid) + rchild->sumRange(mid, end);
    }
};

class NumArray {
    IntervalTree<vector<int>::iterator> tree;
    std::reference_wrapper<vector<int>> arr;

public:
    NumArray(vector<int>& nums) : tree(nums.begin(), nums.end()), arr(nums) {}

    void update(int index, int val) {
        tree.update(arr.get().begin() + index, val);
    }

    int sumRange(int left, int right) {
        return tree.sumRange(arr.get().begin() + left,
                             arr.get().begin() + right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    vector<int> vec{1, 3, 5};
    NumArray    na(vec);
    cout << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << na.sumRange(0, 2) << endl;
}
