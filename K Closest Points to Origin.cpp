//https://leetcode.com/problems/k-closest-points-to-origin/
//TC: O(n log k) SC: O(k)
class Solution {
    
    static int get_distance_from_origin(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    } 
    
    struct Comp {
        bool operator()(vector<int> point1, vector<int> point2) const {
            return get_distance_from_origin(point1) < get_distance_from_origin(point2);
        }
    } compHeap;
    
    vector<vector<int>> get_k_closest_using_heap(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comp> maxHeap(compHeap);
        
        for (auto e: points) {
            maxHeap.push(e);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();   
        }
        return result;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
         return get_k_closest_using_heap(points, K);
    }
};
