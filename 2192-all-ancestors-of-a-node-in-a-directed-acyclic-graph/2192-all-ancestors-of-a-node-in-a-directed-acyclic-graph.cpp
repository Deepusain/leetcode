class Solution {
public:
    void dfs(vector<int> adj[],int s,vector<bool>& viz){
        viz[s]=true;
        for(auto x:adj[s]){
            if(!viz[x]){
                dfs(adj,x,viz);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<vector<int>> rez(n);
        for(int i=0;i<n;i++){
            vector<bool>viz(n,false);
            dfs(adj,i,viz);
            
            for(int j=0;j<n;j++){
                if(viz[j] && i!=j){
                    rez[j].push_back(i);
                }
            }
        }
        return rez;
    }
};