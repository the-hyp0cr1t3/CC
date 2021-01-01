/* Disjoint Set Union or Union Find */
// (https://cp-algorithms.com/data_structures/disjoint_set_union.html)

struct DSU {
    int n, components;
    vector<int> data, rootID, roots; 
    
    DSU(int n): n(n), components(n), data(n+1, -1), rootID(n+1, -1) {}
    
    int par(int x) { 
        return data[x] < 0 ? x : data[x] = par(data[x]); 
    }
    
    int SZ(int x) { 
        return -data[par(x)]; 
    }
    
    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; components--;
        return true;
    }
    
    void getRoots() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(data[i] >= 0) continue;
            rootID[i] = cnt++;
            roots.pb(i);
        } assert(cnt == components);
    }
};
