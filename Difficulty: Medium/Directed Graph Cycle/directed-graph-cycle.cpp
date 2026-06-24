class Solution {
  public:
  bool dfs(int source,vector<vector<int>>&adj,vector<int>&colours){
  // in thsi 0--> means not visited
  // 1 --> means currently in stack;
  // 2 ---> measn visited;
  colours[source]=1;
  for(auto &child:adj[source]){
      if(colours[child]==0){
         if (dfs(child,adj,colours)) return true;
      }
      if(colours[child]==1)return true ; // this refers tht out dfs is currently in stack;
      
  }
  colours[source]=2;
  return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n=V;
        vector<vector<int>>adj(n);
        // vector<bool>visited(n,false);
        // vector<bool>recursive_path(n,false);
        
        vector<int>colours(n);
        for(auto &a:edges){
            int u=a[0];
            int v=a[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(colours[i]==0){
              if(dfs(i,adj,colours))return true;
        }
        }
        return false;
    }
    
};