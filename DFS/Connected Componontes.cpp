#include <iostream>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define sp " "
#define el '\n'
#define int long long
#define FAST_IO cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define f first
#define srta(v) sort(v.begin(), v.end())
#define srtd(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define prntv(vec) for(auto i : vec) cout << i << " "
#define memo(m, v) memset(m, v, sizeof(m))
#define inpFile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
const int MOD = /*998244353;*/ 1e9 + 7;
const long long oo = 1e16;
const int N = 2e5 + 5;
string yes = "Yes", no = "No";
/*
<--------------------CODE GOES FROM HERE --------------------->
*/
int vis[N];
vector<int> adj[N];
void dfs(int u){
		vis[u] = 1;
		for(auto v : adj[u]){
				if(!vis[v])
						dfs(v);
		}
}
void S(int T = 0){
		int n , m; cin >> n >> m;
		int cc = 0;
		for(int i = 0 ; i < m ; i++){
				int u , v; cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
		}
		for(int i = 1 ; i <= n ; i++){
				if(!vis[i]){
						dfs(i);
						cc++;
				}
		}
		cout << cc;
}
signed main(){
		FAST_IO
		int TESTCASES = 1;
//	cin >> TESTCASES;
		while(TESTCASES--){
				S();
		}
}