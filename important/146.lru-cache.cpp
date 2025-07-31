/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include<unordered_map>
#include<memory>
using namespace std;

class Node {
public:
    int key;
    int val;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(int key, int val):key{key},val{val},prev{nullptr},next{nullptr} {}
};

class LRUCache {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    unordered_map<int, shared_ptr<Node>> cache_map;
    int capacity;

    void append(shared_ptr<Node> val) {
        if (!head) {
            head = val;
            tail = val;
            return;
        }
        tail->next = val;
        val->prev = tail;
        tail = val;
    }

    void remove(shared_ptr<Node> val) {
        if (val->prev) {
            val->prev->next = val->next;
        }
        if (val->next) {
            val->next->prev = val->prev;
        }
        if (val == head) head = head->next;
        if (val == tail) tail = tail->prev;
        val->next = nullptr;
        val->prev = nullptr;
    }

    void update(shared_ptr<Node> val) {
        remove(val);
        append(val);
    }

    void deleteHead() {
        shared_ptr<Node> toRemove = head;
        remove(toRemove);
        cache_map.erase(toRemove->key);
    }

public:
    LRUCache(int capacity):capacity{capacity},head{nullptr},tail{nullptr}{
        
    }
    
    int get(int key) {
        if (cache_map.contains(key)) {
            update(cache_map[key]);
            return cache_map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_map.contains(key)) {
            update(cache_map[key]);
            cache_map[key]->val = value;
        } else {
            if (cache_map.size() == capacity)
                deleteHead();
            shared_ptr<Node> toAdd = make_shared<Node>(key, value);
            append(toAdd);
            cache_map[toAdd->key] = toAdd;
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

