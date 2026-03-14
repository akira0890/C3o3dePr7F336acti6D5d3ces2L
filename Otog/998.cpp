#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int max;
    int unique;
};

class SegmentTree {
    int n;
    std::vector<Node> tree;

public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void build(const std::vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = {data[start] , 1};
            return;
        }
        int mid = (start + end) / 2;
        build(data, 2 * node, start, mid);
        build(data, 2 * node + 1, mid + 1, end);
        
        tree[node].max = std::max(tree[2 * node].max, tree[2 * node + 1].max);
        tree[node].unique = (std::unique(data.begin() + start , data.begin() + end)) - data.begin();
    }

    Node query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return {0, 0};
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left_res = query(2 * node, start, mid, L, R);
        Node right_res = query(2 * node + 1, mid + 1, end, L, R);
        
        return {
            std::max(left_res.max, right_res.max),
            std::max(left_res.unique, right_res.unique)
        };
    }

    Node query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , ans = 0 , currmax = 0 , unique = 0; std::cin >> n;
    std::vector<int> v(n) , visited(n , false);
    std::queue<int> q;

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    SegmentTree ST(v);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            Node d = ST.query(i,j);
            ans = std::max(ans , d.max * d.unique);
        }
    }
    ans = std::max(ans , currmax * unique);

    std::cout << ans;
}