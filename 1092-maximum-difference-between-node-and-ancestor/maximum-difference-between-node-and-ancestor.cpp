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
    int findMaxDiff(TreeNode* root, int maxVal, int minVal)
    {
        // node value is positive or zero
        if(root==NULL) 
        {
            return abs(maxVal-minVal);
        }
        maxVal=max(maxVal, root->val);
        minVal = min(minVal, root->val);
        int maxOfLeft = findMaxDiff(root->left,maxVal,minVal);
        int maxOfRight = findMaxDiff(root->right,maxVal,minVal);

        return max(maxOfLeft,maxOfRight);

    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxVal=INT_MIN;
        int minVal=INT_MAX;
        return findMaxDiff(root,maxVal,minVal);
    }
};