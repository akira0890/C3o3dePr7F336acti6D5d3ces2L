#include <iostream>
#include <vector>

class SegmentTree {
    int n;
    std::vector<int> tree;
public:
    SegmentTree(int n) : n(n) {
        tree.resize(4*n+1);
    }

    void build(int Node, int start , int end) {
        if (start == end) {
            tree[Node] = 1;
            return;
        }

        int mid = (start + end)/2;
        build(Node * 2 , start , mid);
        build(Node * 2 + 1 , mid+1 , end);

        tree[Node] = tree[Node*2] + tree[Node*2+1];
    }

    int QueryNUpdate(int Node , int start , int end , int k) {
        if (start == end) {
            tree[Node] = 0;
            return start;
        }

        int mid = (start + end)/2 , val;
        if (tree[2 * Node] >= k) val = QueryNUpdate(Node*2 , start , mid , k);
        else val = QueryNUpdate(Node*2+1 , mid+1 , end , k - tree[Node*2]);

        tree[Node] = tree[Node*2] + tree[Node*2+1];
        return val;
    }

    int GetRemain() { return tree[1]; }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    SegmentTree ST(n);

    ST.build(1,1,n);
    int curr = 1;

    for (int i = 0 ; i < n ; i++) {
        int remain = ST.GetRemain();

        int nextPos = (curr + m - 1) % remain;
        if (nextPos == 0) nextPos = remain;
        curr = nextPos;

        std::cout << ST.QueryNUpdate(1,1,n,nextPos) << ' ';
    }
}