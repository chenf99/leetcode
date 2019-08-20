/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.37%)
 * Total Accepted:    333.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity  );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
#include <unordered_map>
using std::unordered_map;

class LRUCache {
private:
    struct ListNode{
        ListNode *prev, *next;
        int key, value;
        ListNode(int key, int value): key(key), value(value) {
            prev = NULL;
            next = NULL;
        }
    };
    ListNode *head, *tail;
    int capacity;
    int size;
    unordered_map<int, ListNode*> hash_map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hash_map.find(key) == hash_map.end()) return -1;
        ListNode* node = hash_map[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        return node->value;
    }
    
    void put(int key, int value) {
        //更新节点值
        if (hash_map.find(key) != hash_map.end()) {
            ListNode *node = hash_map[key];
            node->value = value;
            get(key);//利用get函数直接把节点移动到链表头部
            return;
        }
        //添加节点
        ListNode *node = new ListNode(key, value);
        hash_map[key] = node;
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        size++;
        if (size > capacity) {
            ListNode *tmp = tail->prev;
            tail->prev = tmp->prev;
            tmp->prev->next = tail;
            hash_map.erase(tmp->key);
            delete tmp;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */