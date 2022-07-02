/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include "common.hpp"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start

class Solution {
    map<Node*, Node*> visited{{nullptr, nullptr}};

public:
    Node* cloneGraph(Node* node) {
        auto it = visited.find(node);
        if (it != visited.end()) {
            return it->second;
        }
        auto new_node = new Node(node->val);
        visited[node] = new_node;
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return new_node;
    }
};
// @lc code=end
