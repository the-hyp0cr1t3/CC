/* Disjoint Set Union or Union Find */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%203%5D%20Spanning%20Trees/%5BPt%201%5D%20Disjoint%20Set%20Union%20%28Union%20Find%29.md
*/

struct DSU {
    int n, components;
    vector<int> data, rootID, roots;
    
    DSU(int n): n(n), components(n), data(n + 1, -1), rootID(n + 1, -1) {}
    
    int par(int x) { 
        return data[x] < 0? x : data[x] = par(data[x]);
    }
    // data[x] = -ve size of component if root, else parent of x (>= 0)
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
    
    // call only once
    void getRoots() {
        roots.reserve(components);
        for(int i = 0; i < n; i++) {
            if(data[i] < 0) {
                rootID[i] = roots.size();
                roots.push_back(i);
            }
        }
    }
};


// ----------------------------------------------
/* v2 */

vector<int> par(n + 1, -1);         // par[x] = -ve size of component if root, else parent of x (>= 0)

auto get_par = [&par](int A) {
    while(par[A] >= 0) {
        if(par[par[A]] >= 0)
            par[A] = par[par[A]];
        A = par[A];
    } return A;
};

auto merge = [&get_par, &par](int A, int B) {
    A = get_par(A); B = get_par(B);
    if(A == B) return false;
    if(-par[A] < -par[B]) swap(A, B);
    par[A] += par[B]; par[B] = A;
    return true;
};
