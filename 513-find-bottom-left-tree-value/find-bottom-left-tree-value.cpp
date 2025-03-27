/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        vector<vector<int>>lvl;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
           
            int n = q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();
                temp.push_back(x->val);
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            lvl.push_back(temp);
        }
        return lvl.back()[0];
    }
};