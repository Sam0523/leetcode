/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <list>
#include <unordered_map>
#include <utility>

// @lc code=start
class LRUCache
{
	int                                                  capacity;
	std::list<std::pair<int, int>>                       CacheList;
	std::unordered_map<int, decltype(CacheList.begin())> CacheMap;

public:
	LRUCache(int capacity) : capacity(capacity), CacheMap(capacity) {}

	int get(int key)
	{
		auto it = CacheMap.find(key);
		if (it != CacheMap.end())
		{
			CacheList.splice(CacheList.begin(), CacheList, it->second);
			return it->second->second;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value)
	{
		auto it = CacheMap.find(key);
		if (it != CacheMap.end())
		{
			it->second->second = value;
			CacheList.splice(CacheList.begin(), CacheList, it->second);
		}
		else
		{
			CacheList.emplace_front(key, value);
			CacheMap.emplace(key, CacheList.begin());
			if (CacheList.size() > capacity)
			{
				CacheMap.erase(CacheList.back().first);
				CacheList.pop_back();
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
