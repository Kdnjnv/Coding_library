#include<iostream>
#include<vector>
#include<queue>
#define  ll long long int
#define MAX 100001
using namespace std;

vector<int> adj[MAX];  // adjacency list representation
int n; // number of nodes

vector<int> d, p;
vector<bool> visited;

void init(int n){
    for(int i=0;i<=n;++i){
        adj[i].clear();
    }
    visited.resize(n,false);
    d.resize(n,0);
    p.resize(n);
}

void bfs(int s){
    queue<int> q;

    q.push(s);
    p[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();++i){
            int v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                p[v] = u;
                d[v] = d[u] + 1;
            }
        }
    }
}

vector<int> shortest_path(int u){
    vector<int> path;
    if(visited[u]){
        for(;u != -1;u = p[u]){
            path.push_back(u);
        }
    }
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    int m;
    cin>>n>>m;

    init(n);

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(0);
    vector<int> ans = shortest_path(2);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}




