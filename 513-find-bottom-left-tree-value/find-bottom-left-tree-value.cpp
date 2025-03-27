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
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){ 
            int n = q.size();
            bool flag =false;
            for(int i=0;i<n;i++){
                TreeNode* x = q.front();
                if(flag==false and !x->left and !x->right){
                    ans=x->val;
                    flag=true;
                }
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return ans;
    }
};