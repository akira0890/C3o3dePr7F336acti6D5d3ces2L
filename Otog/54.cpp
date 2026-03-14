#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class SegmentTree {
    int n;
    std::vector<int> ST;
private:

    void update(int Node , int l, int r, int idx , int v) {
        if (l == r) {
            ST[Node] = std::max(ST[Node] , v);
            return;
        }

        int mid = (l+r)/2;
        if (idx <= mid) update(Node*2+1 , l , mid , idx,v);
        else update(Node*2+2 , mid+1 , r , idx,v);

        ST[Node] = std::max(ST[Node*2+1] , ST[Node*2+2]);
    }

    int query(int Node , int start, int end , int l, int r) {
        if (r < start || l > end) return 0;

        if (l <= start && end <= r) return ST[Node];

        int mid = (start + end)/2;

        int left = query(Node*2+1 , start , mid , l , r);
        int right = query(Node*2+2 , mid+1 , end , l , r);
        // std::cout << "left: " << start << ' ' << mid << ' ' << left << "right: " << mid+1 << ' ' << end << ' ' << right << '\n';

        return std::max(left , right);
    }

public:
    SegmentTree(int N) {
        n = N;
        ST.resize(4*n,0);
    }

    void Update(int idx , int v) {
        update(0,0,n-1,idx, v);
    }

    int Query(int start , int end) {
        return query(0,0,n-1, start , end);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    std::vector<int> v(n) , sorts(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    sorts = v;
    std::sort(sorts.begin() , sorts.end());
    sorts.erase(std::unique(sorts.begin() , sorts.end()) , sorts.end());
    std::unordered_map<int , int> index;
    for (int i = 0 ; i < sorts.size() ; i++) index[sorts[i]] = i;

    SegmentTree St(sorts.size());
    int ans = 0;

    for (int i = 0 ; i < n ; i++) {
        int curr = St.Query(0 , index[v[i]]-1) +1;
        St.Update(index[v[i]] , curr);
        ans = std::max(ans , curr);
    }

    std::cout << ans;
}