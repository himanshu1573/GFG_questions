class Solution {
  public:
  bool dfs(int source,vector<vector<int>>&adj,
       vector<bool>&visited,int  parent){
           visited[source]=true;
           for(auto child:adj[source]){
               if(!visited[child]){
                  if( dfs(child,adj,visited,source))
                   return true;
               }else if(parent!=child) return true;
           }
           return false;
       }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
       int n=V;
       vector<vector<int>>adj(n);
       vector<bool>visited(n,false);
    //   vector<int>parent(n);
       
       for(auto &a:edges){
           int u=a[0];
           int v=a[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
           
       }
       for(int i=0;i<n;i++){
           if(!visited[i]){
              if(dfs(i,adj,visited,-1))
                return true;
           }
       }
       return false;
    }
};