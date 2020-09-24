  // init
  vector<int> seg(2*n);
  for(i = 0; i < n; i++)
      seg[i+n] = a[i];

  // build
  for(i = n-1; i; i--)
      seg[i] = seg[i<<1] + seg[i<<1|1];

  // point updates
  auto update = [&](int pos, int val) {
      for(seg[pos+=n] = val; pos >>= 1;)
          seg[pos] = seg[pos<<1] + seg[pos<<1|1];
  };

  // query [l, r) 0-based indexing
  auto query = [&](int l, int r) {
      int res = 0;
      for(l += n, r += n; l < r; l >>= 1, r>>= 1) {
          if(l&1) res += seg[l++];
          if(r&1) res += seg[--r];
      } return res;
  };
