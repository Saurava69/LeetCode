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
    void solve(TreeNode* root, vector<int>&temp,int &result)
    {
        if(root==NULL) return;
        temp[root->val]++;

        if(!root->left and !root->right)
        {
            int oddCount=0;
            for(int i=1;i<=9;i++)
            {
                if(temp[i]%2!=0) oddCount++;
            }
            if(oddCount<=1) result+=1;
        }
        solve(root->left,temp,result);
        solve(root->right,temp,result);
        //back track since temp is passed by reference
        temp[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>temp(10,0);
        int result=0;
        solve(root,temp,result);
        return result;
    }
};