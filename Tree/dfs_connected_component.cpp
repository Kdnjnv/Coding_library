#include<iostream>
#include<vector>
#include<queue>
#define  ll long long int
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
vector<bool> visited;
vector<int> comp;

void init(int n){
	for(int i=0;i<=n;++i){
		adj[i].clear();
	}
	visited.resize(n,false);
}

void dfs(int v){
	visited[v] = true;
	comp.push_back(v);
	for(int i=0;i<adj[v].size();++i){
		int u = adj[v][i];
		if(!visited[u]){
			dfs(u);
		}
	}
}

vector<vector<int> > find_set(int n){
	int count = 0;
	vector<vector<int> > comp_vec;
	for(int i=0;i<n;++i){
		if(!visited[i]){
			++count;
			comp.clear();
			dfs(i);
			comp_vec.push_back(comp);
		}
	}
	return comp_vec;
}

int main(){
	int n,m;
	cin>>n>>m;
	init(n);
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int> > ans = find_set(n);
	for(int i=0;i<ans.size();++i){
		for(int j=0;j<ans[i].size();++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans.size()<<endl;
}