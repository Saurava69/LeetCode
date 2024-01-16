//BFS Solution

// class Solution{
//     public:
// 	void makeGraph(unordered_map<int, vector<int>>&adj,int  parent, TreeNode* root)
// 	{
// 		if(root==NULL) return;
		 
// 		if(parent!=-1) 
// 		{
// 			adj[root->val].push_back(parent);
// 		}
// 		if(root->left) adj[root->val].push_back(root->left->val);
// 		if(root->right) adj[root->val].push_back(root->right->val);
		
// 		// call function to create the Graph
		
// 		makeGraph(adj,root->val,root->left);
// 		makeGraph(adj, root->val, root->right);
	
// 	}
// 	int amountOfTime(TreeNode* root, int start) {
// 		unordered_map<int, vector<int>>adj;
// 		//create Graph
// 		makeGraph(adj, -1 , root);
// 		//Apply BFS
// 		queue<int>q;
// 		unordered_set<int>visited;
// 		q.push(start);
// 		visited.insert(start);
// 		int minutes=0;
// 		while(!q.empty())
// 		{
// 			int n= q.size();
// 			while(n--)
// 			{
// 				int curr=q.front();
// 				q.pop();
// 				for(auto &nbr:adj[curr])
// 				{
// 					if(visited.find(nbr)==visited.end()) 
// 					{
// 						q.push(nbr);
// 						visited.insert(nbr);
// 					}
// 				}
// 			}
// 			minutes++;
// 		}
// 		return minutes-1;
// 	}
// };

// DFS 

class Solution {
private:
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    int traverse(TreeNode* root, int start) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        } else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
};

/*
Let nnn be the number of nodes in the tree.

Time complexity: O(n)O(n)O(n)

Traversing the tree with a DFS costs O(n)O(n)O(n) as we visit each node exactly once.

Space complexity: O(n)O(n)O(n)

The space complexity of DFS is determined by the maximum depth of the call stack, which corresponds to the depth of the tree (or the graph in our case). In the worst case, if the tree is completely unbalanced (e.g., a linked list), the call stack can grow as deep as the number of nodes, resulting in a space complexity of O(n)O(n)O(n).
*/