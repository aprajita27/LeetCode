/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> v;
            int size = q.size();
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp == NULL)
                    v.push_back(INT_MIN);
                else
                    v.push_back(temp -> val);
                if(temp)
                {
                    if(temp -> left)
                        q.push(temp -> left);
                    else
                        q.push(NULL);
                    if(temp -> right)
                        q.push(temp -> right);
                    else
                        q.push(NULL);
                }
            }
            vector<int> v1 = v;
            reverse(v.begin(),v.end());
            if(v1 != v)
                return false;
        }
        return true;
    }
};
