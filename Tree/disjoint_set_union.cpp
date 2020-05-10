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

void add(int delta,int i){
    i++;

    while(i <= n){
        bit[i] += delta;
        i += i & (-i);
    }
}

int main(){
    int m;
    cin>>n>>m;

    init(n);

    vector<int> a(n);

    for(int i=0;i<n;++i){
        cin>>a[i];
        add(a[i],i);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum(l,r)<<endl;
    }
}

