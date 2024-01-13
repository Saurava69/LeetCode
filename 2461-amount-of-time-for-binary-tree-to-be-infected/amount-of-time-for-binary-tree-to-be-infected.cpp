class Solution{
    public:
	void makeGraph(unordered_map<int, vector<int>>&adj,int  parent, TreeNode* root)
	{
		if(root==NULL) return;
		 
		if(parent!=-1) 
		{
			adj[root->val].push_back(parent);
		}
		if(root->left) adj[root->val].push_back(root->left->val);
		if(root->right) adj[root->val].push_back(root->right->val);
		
		// call function to create the Graph
		
		makeGraph(adj,root->val,root->left);
		makeGraph(adj, root->val, root->right);
	
	}
	int amountOfTime(TreeNode* root, int start) {
		unordered_map<int, vector<int>>adj;
		//create Graph
		makeGraph(adj, -1 , root);
		//Apply BFS
		queue<int>q;
		unordered_set<int>visited;
		q.push(start);
		visited.insert(start);
		int minutes=0;
		while(!q.empty())
		{
			int n= q.size();
			while(n--)
			{
				int curr=q.front();
				q.pop();
				for(auto &nbr:adj[curr])
				{
					if(visited.find(nbr)==visited.end()) 
					{
						q.push(nbr);
						visited.insert(nbr);
					}
				}
			}
			minutes++;
		}
		return minutes-1;
	}
};
