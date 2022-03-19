/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include "common.hpp"

// @lc code=start
class LFUCache {
    struct Bucket {
        unsigned freq{0u};
        std::list<std::pair<int, int>> kv_list;
        Bucket(unsigned f) : freq(f) {}
    };

    std::list<Bucket> bkt_list;
    std::unordered_map<int,
                       std::pair<std::list<Bucket>::iterator,
                                 std::list<std::pair<int, int>>::iterator>>
        key_iter_map;
    int cap;

public:
    LFUCache(int capacity) : cap(capacity) {}

    int *get_impl(int key) {
        if (auto key_iter_map_iter = key_iter_map.find(key);
            key_iter_map_iter != key_iter_map.end()) {
            auto bkt_iter = key_iter_map_iter->second.first;
            auto kv_iter = key_iter_map_iter->second.second;

            if (bkt_iter->kv_list.size() == 1 &&
                std::next(bkt_iter)->freq != bkt_iter->freq + 1) {
                bkt_iter->freq++;
                return &kv_iter->second;
            }

            // remove value from old bucket
            auto kv = std::move(*kv_iter);
            bkt_iter->kv_list.erase(kv_iter);

            unsigned freq = bkt_iter->freq + 1;
            {
                auto old_bkt = bkt_iter;
                ++bkt_iter;
                // delete empty bucket
                if (old_bkt->kv_list.empty()) {
                    bkt_list.erase(old_bkt);
                }
            }
            // find new bucket
            if (bkt_iter == bkt_list.end() || bkt_iter->freq != freq) {
                assert(bkt_iter == bkt_list.end() || bkt_iter->freq > freq);
                bkt_iter = bkt_list.emplace(bkt_iter, freq);
            }

            // put value in new bucket
            bkt_iter->kv_list.push_front(std::move(kv));
            key_iter_map_iter->second.second = bkt_iter->kv_list.begin();
            key_iter_map_iter->second.first = bkt_iter;

            return &bkt_iter->kv_list.front().second;
        }
        return nullptr;
    }

    int get(int key) {
        int *pvalue = get_impl(key);
        if (pvalue) {
            return *pvalue;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        int *pvalue = get_impl(key);
        if (pvalue) {
            // update
            *pvalue = value;
            return;
        }

        // release if full
        if (key_iter_map.size() == cap) {
            if (cap == 0) {
                return;
            }
            auto &bkt = bkt_list.front();
            assert(!bkt.kv_list.empty());
            key_iter_map.erase(bkt.kv_list.back().first);
            bkt.kv_list.pop_back();
            if (bkt.kv_list.empty()) {
                bkt_list.pop_front();
            }
        }

        // get bucket with freq = 1
        auto bkt_iter = bkt_list.begin();
        if (bkt_iter == bkt_list.end() || bkt_iter->freq != 1) {
            bkt_iter = bkt_list.insert(bkt_iter, Bucket(1));
        }

        // insert
        bkt_iter->kv_list.emplace_front(key, value);
        key_iter_map[key] = std::make_pair(bkt_iter, bkt_iter->kv_list.begin());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    assert(lfu.get(1) == 1);
    lfu.put(3, 3);
    assert(lfu.get(2) == -1);
    assert(lfu.get(3) == 3);
    lfu.put(4, 4);
    assert(lfu.get(1) == -1);
    assert(lfu.get(3) == 3);
    assert(lfu.get(4) == 4);
    LFUCache lfu2(0);
    lfu2.put(0, 0);
    assert(lfu2.get(0) == -1);
}
