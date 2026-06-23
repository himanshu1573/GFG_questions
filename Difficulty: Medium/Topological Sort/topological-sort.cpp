class Solution {
  public:
  void dfs(int source,vector<vector<int>>&adj,stack<int>&st,  vector<bool>&visited){
      visited[source]=true;
      for(auto &child:adj[source]){
          if(!visited[child])dfs(child,adj,st,visited);
      }
      st.push(source);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n=V;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        // queue<int>q;
        stack<int>st;
        vector<int>ans;
        for(auto &a:edges){
            int u=a[0];
            int v=a[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(i,adj,st,visited);
        }
        while(!st.empty()){
            int front=st.top();
            ans.push_back(front);
            st.pop();
        }
        return ans;
    }
};