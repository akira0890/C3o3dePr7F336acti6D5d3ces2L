#include <iostream>
#include <vector>

class SegmentTree {
    int n;
    std::vector<int> tree;

    // -- Update --
    void update(int node , int l , int r , int ind , int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if (ind <= mid) update(node*2+1 , l , mid , ind , val);
        else            update(node*2+2 , mid+1 , r , ind ,val);

        tree[node] = std::max(tree[node*2+1] , tree[node*2+2]);
    }

    // -- Query --
    int query(int node , int start , int end , int l , int r) {
        if (l < start && r > end) return 0;
        else if (l >= start && r <= end) return tree[node];

        int mid = l+(r-l)/2;
        int v1 = query(node*2+1 , start , end , l , mid);
        int v2 = query(node*2+2 , start , end , mid+1 , r);

        return std::max(v1 , v2);
    }

public:

    // -- Build --
    SegmentTree(const std::vector<int> &v) {
        n = v.size();
        tree.resize(4*n+1,0);
    }

    void Update(int ind , int val) {
        update(0,0,n-1,ind,val);
    }

    int Query(int l , int r) {
        return query(0,l,r,0,n-1);
    }
};