#include<bits/stdc++.h>
#include<vector>
#include<queue>
#define  ll long long int
#define MAX 100001
using namespace std;

vector<int> adj[MAX];

vector<int> color;
vector<int> time_in,time_out;

//for simple dfs
vector<bool> visited;

int dfs_timer = 0;

void init(int n){
	color.resize(n,0);
	time_in.resize(n,-1);
	time_out.resize(n,-1);
	dfs_timer = 0;
	for(int i=0;i<n;++i){
		adj[i].clear();
	}
	//for simple dfs
	visited.resize(n,false);
}

void dfs(int v){
	visited[v] = true;
	for(int i=0;i<adj[v].size();++i){
		int u = adj[v][i];
		if(!visited[u]){
			dfs(u);		
		}
	}
}

void dfs2(int v){

	time_in[v] = dfs_timer++;
	color[v] = 1;
	for(int i=0;i<adj[v].size();++i){
		int u = adj[v][i];
		if(color[u] == 0){
			dfs(u);
		}
	}
	color[v] = 2;
	time_out[vf] = dfs_timer++;

}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
}