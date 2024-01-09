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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        DFS(root1, t1);
        DFS(root2, t2);
        return t1==t2;
    }
    
    void DFS(TreeNode* root, string& s) {
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL)
        {

            s.push_back(root->val+'0');
            s.push_back('#');
        } 
        DFS(root->left, s);
        DFS(root->right, s);
    }
};