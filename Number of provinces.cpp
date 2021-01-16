//https://leetcode.com/problems/number-of-provinces/
//TC: O(n) SC: O(n) 
class Solution {
    vector<int> id_of_set;
    vector<int> sz_of_set;
    int num_of_components;
    int num_of_elements;
    
public:
    int find(int i) {
        return id_of_set[i] == i ? i : id_of_set[i] = find(id_of_set[i]);
    }
    
    bool in_same_set(int i, int j) {
        return find(i) == find(j);
    }
    
    void merge(int i, int j) {
        if (in_same_set(i,j))
            return;
        else {
            int root1 = find(i);
            int root2 = find(j);
            num_of_components--;
            if (sz_of_set[root1] > sz_of_set[root2]){
                sz_of_set[root1] += 1;
                id_of_set[root2] = root1;
            }   else {
                sz_of_set[root2] += 1;
                id_of_set[root1] = root2;
            }
        }
    }
    
    int get_circle_num(vector<vector<int>>& m) {
        num_of_elements = m.size();
        num_of_components = m.size();
        for (int i = 0; i < m.size(); ++i) {
            id_of_set.push_back(i);
            sz_of_set.push_back(1);
        }
        
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[0].size(); ++j) {
                if (m[i][j] == 1)
                    merge(i,j);
            }
        }
        return num_of_components;
    }
    
    int findCircleNum(vector<vector<int>>& M) { 
        return get_circle_num(M);     
    }
};
