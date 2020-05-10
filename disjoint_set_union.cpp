class UnionFind{
public:
    
    vector<int> parent;
    vector<int> size;

    void init(){
        parent.clear();
    }

    void make_set(int n){
        for(int i=0;i<n;++i){
            parent.push_back(i);
            size[i] = 1;
        }
    }

    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int u,int v){
        int a = find_set(u);
        int b = find_set(v);

        if(a != b){
            if(size[a] < size[b]){
                swap(a,b);
            }
            parent[b] = a;
            size[b] += size[a];
        }
    }
};
