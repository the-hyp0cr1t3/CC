/* Closest pair of points */

/*
    https://cp-algorithms.com/geometry/nearest_points.html
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct point {
    int x, y, id;
};

pair<int, int> ans;
int64_t min_val = 1e18;
vector<point> a;

auto update = [] (const point& p, const point& q) {
    int64_t dist = 1ll*(p.x-q.x)*(p.x-q.x) + 1ll*(p.y-q.y)*(p.y-q.y);
    if(dist < min_val) 
        min_val = dist, ans = make_pair(p.id, q.id);
};

void recur(int l, int r) {
    int i, j;
    if(r-l <= 3) {
        sort(a.begin()+l, a.begin()+r, [](const point& A, const point& B) { 
            return A.y == B.y? A.x < B.x : A.y < B.y; 
        });
        for(i = l; i < r; i++) 
            for(j = l; j < i; j++)
                update(a[i], a[j]);
        return;
    }

    int m = (l+r)/2;
    recur(l, m); recur(m, r);

    static point tmp[N];
    merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+r, tmp,
        [](const point& A, const point& B) { return A.y == B.y? A.x < B.x : A.y < B.y; });

    copy(tmp, tmp+r-l, a.begin()+l);

    int top = -1;
    for(i = l; i < r; i++) {
        if(abs(a[i].x-a[m].x) >= min_val) continue;
        for(j = top; ~j and a[i].y-tmp[j].y < min_val; j--)
            update(a[i], a[j]);
        tmp[++top] = a[i];
    }
}

int32_t main() {
    int i, n;
    cin >> n; a.resize(n);
    for(i = 0; i < n; i++) 
        cin >> a[i].x >> a[i].y, a[i].id = i;

    sort(a.begin(), a.end(), [](const point& A, const point& B) { 
        return A.x == B.x? A.y < B.y : A.x < B.x; 
    });
    
    recur(0, n);
    double dist = sqrt(min_val);
    cout << fixed << setprecision(4);
    cout << dist << '\n' << ans.first << ' ' << ans.second;

    return 0;
}