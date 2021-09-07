/* Dijkstra's */

/*
    https://github.com/the-hyp0cr1t3/CC/blob/master/Beginner%20Topics/%5BS5%5D%20Do%20you%20understand%20the%20graphity%20of%20this%20situation/%5BEP%202%5D%20Shortest%20paths/%5BPt%202%5D%20Dijkstra%27s.md
*/

auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

vector<vector<int>> g(n);       // adjacency list
vector<int64_t> d(n, INF);
vector<int> par(n, -1);

auto dijkstra = [&] (int root) {
    struct state {
        int v; int64_t dist;
        state(int v, int64_t dist): v(v), dist(dist) {}
        bool operator<(const state& o) const { 
            return dist > o.dist; 
        }
    }; 
    
    priority_queue<state> pq;
    pq.emplace(root, d[root] = 0);

    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        if(top.dist > d[top.v]) continue;
        for(auto& [to, w]: g[top.v])
            if(chmin(d[to], top.dist + w))
                pq.emplace(to, d[to]), par[to] = top.v;
    }

};