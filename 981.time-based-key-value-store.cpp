/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include "common.hpp"

// @lc code=start
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> _Tmap;

public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        _Tmap[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto map_it = _Tmap.find(key);
        if (map_it != _Tmap.end()) {
            auto vector_it = upper_bound(
                map_it->second.begin(), map_it->second.end(), timestamp,
                [](const int& k, const pair<int, string>& kv) {
                    return k < kv.first;
                });
            if (vector_it != map_it->second.begin()) {
                return vector_it[-1].second;
            }
        }
        return string();
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
