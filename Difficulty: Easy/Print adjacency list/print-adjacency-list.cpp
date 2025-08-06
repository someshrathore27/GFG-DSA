class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int n, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>>ans(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
};