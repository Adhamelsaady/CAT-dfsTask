class Solution {
public:
    map<int,vector<int>>adj;
vector<int>ans;
map<int,bool>vis;
void dfs(int u){
		vis[u] = 1;
		for(auto v : adj[u]){
				if(!vis[v]) {
						ans.push_back(v);
						dfs(v);
				}
		}
}
vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		int n = adjacentPairs.size();
		for(int i = 0; i < n ; i++){
				int u = adjacentPairs[i][0];
				int v = adjacentPairs[i][1];
				adj[u].push_back(v);
				adj[v].push_back(u);
		}
		int start = 0;
		for(auto it : adj){
				if(it.second.size() == 1){
						start = it.first;
						break;
				}
		}
		ans.push_back(start);
		dfs(start);
		return ans;
}
};