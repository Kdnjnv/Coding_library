#include<iostream>
#include<vector>
#define  ll long long int
#define MAX 100001
using namespace std;

vector<int> bit;
int n;

void init(int num){
    bit.resize(n+1,0);
    n = num;
}

int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += bit[i];
        i -= i & (-i);
    }
    return ret;
}

int sum(int l,int r){
    return sum(r) - sum(l-1);
}

//point update range query
void add(int i,int delta){
    i++;

    while(i <= n){
        bit[i] += delta;
        i += i & (-i);
    }
}

//range update poin query
void range_add(int l,int r,int delta){
    add(l,delta);
    add(r+1,-delta);
}

int main(){
    int m;
    cin>>n>>m;

    init(n);

    vector<int> a(n);

    for(int i=0;i<n;++i){
        cin>>a[i];
        add(i,a[i]);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum(l,r)<<endl;
    }
}

