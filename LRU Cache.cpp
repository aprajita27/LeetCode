//https://leetcode.com/problems/lru-cache/
// TC: O(1) SC: O(n)
class LRUCache {
    list<pair<int, int>> l;
    int size;
    unordered_map<int, list<pair<int, int>> :: iterator> mp;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    //O(1)
    int get(int key) {
        if (mp.count(key) <= 0)
            return -1;
        l.splice(l.begin(), l, mp[key]);
        return mp[key] -> second;
    }
    //O(1)
    void put(int key, int value) {
        if(mp.count(key) <= 0)  {
            if (l.size() == size)   {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key, value});
            mp[key] = l.begin();
        }   else {
            mp[key] -> second = value;
            l.splice(l.begin(), l, mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
