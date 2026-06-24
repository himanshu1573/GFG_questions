class Solution {
  public:
  bool dfs(int source,vector<vector<int>>&adj,vector<bool>&visited, vector<bool>&recursive_path){
      visited[source]=true;
      recursive_path[source]=true;
      for(auto child:adj[source]){
          if(!visited[child]){
              if(dfs(child,adj,visited,recursive_path))return true;
          }else if(recursive_path[child]){
              return true;
          }
      }
     recursive_path[source] = false;
    return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n=V;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        vector<bool>recursive_path(n,false);
        for(auto &a:edges){
            int u=a[0];
            int v=a[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
              if(dfs(i,adj,visited,recursive_path))return true;
        }
        }
        return false;
    }
    
};