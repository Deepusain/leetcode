class Solution {
public:
    typedef pair<double , int>p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        
        vector <double>result(n,0);
        
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v= edges[i][1];
            
            double prob = succProb[i];
            
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        } // make adj
        priority_queue<p> pq; //max heap
        result[start] =1; // probability to reach start from start
        pq.push({1.0,start});
        
        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();
            
            for(auto &temp : adj[currNode]){
                double adjProb = temp.second;
                int adjNode = temp.first;
                
                if(result[adjNode]<currProb*adjProb){
                    result[adjNode]=currProb*adjProb;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
        return result[end];
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
//         vector<double> maxProb(n, 0.0);
//         maxProb[start_node] = 1.0;

//         for (int i = 0; i < n - 1; ++i) {
//             bool updated = false;
//             for (int j = 0; j < edges.size(); ++j) {
//                 int u = edges[j][0];
//                 int v = edges[j][1];
//                 double prob = succProb[j];

//                 if (maxProb[u] * prob > maxProb[v]) {
//                     maxProb[v] = maxProb[u] * prob;
//                     updated = true;
//                 }
//                 if (maxProb[v] * prob > maxProb[u]) {
//                     maxProb[u] = maxProb[v] * prob;
//                     updated = true;
//                 }
//             }
//             if (!updated) break;
//         }

//         return maxProb[end_node];
    }
};