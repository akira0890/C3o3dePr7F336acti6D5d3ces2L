#include <iostream>
#include <vector>
#include <climits>

#define pii std::pair<int,int>

class SGT {
    std::vector<pii> tree;
    std::vector<int> arr;
    int n;

    void build(int node , int l , int r) {
        if (l == r) {
            tree[node] = {arr[l] , arr[l]};
            return;
        }
        
        int mid = l + (r-l) / 2;
        build(node*2+1 , l , mid);
        build(node*2+2,mid+1,r);
        
        tree[node] = {std::min(tree[node*2+1].first , tree[node*2+2].first) , std::max(tree[node*2+1].second , tree[node*2+2].second)};
    }
    
    void update(int node , int l , int r , int idx, int val) {
        if (l == r) {
            tree[node] = {val , val};
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        if (idx <= mid) {
            update(node*2+1 , l , mid , idx , val);
        } else {
            update(node*2+2 , mid+1 , r , idx , val);
        }
        
        tree[node] = {std::min(tree[node*2+1].first , tree[node*2+2].first) , std::max(tree[node*2+1].second , tree[node*2+2].second)};
    }
    
    pii query(int node , int start , int end , int l , int r) {
        if (r < start || l > end) return {INT_MAX , INT_MIN};
        if (l <= start && end <= r) return tree[node];
        
        int mid = start + (end - start) / 2;
        pii a = query(node*2+1 , start , mid , l , r);
        pii b = query(node*2+2 , mid+1 , end , l , r);
        
        return {std::min(a.first , b.first) , std::max(a.second , b.second)};
    }
public:
    SGT(int N , const std::vector<int> &v) {
        tree.resize(4*N , {INT_MAX , INT_MIN});
        n = N;
        arr = v;

        build(0,0,N-1);
    }

    void Update(int idx , int val) {
        update(0,0,n-1, idx , val);
    }
    
    pii Query(int l , int r) {
        return query(0,0,n-1,l,r);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<int> v(n);
    int value;
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
    SGT segmentTree(n , v);

    char cmd;
    int s,t;
    while (std::cin >> cmd) {
        std::cin >> s >> t;
        if (cmd == 'U') {
            segmentTree.Update(s,t);
        } else {
            pii ans = segmentTree.Query(s,t);
            std::cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}