#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

struct point {
    int a,b;
};

struct BIT {
    int n;
    std::vector<ull> tree;
    BIT(int n) : n(n), tree(n+1, 0) {}

    void update(int i, ull val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }

    ull query(int i) {
        ull res = 0;
        for (; i > 0 ; i -= i & -i) res += tree[i];
        return res;
    }

    ull queryRange(int l, int r) {
        return query(r) - query(l-1);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<point> p(n);
    std::vector<int> b_coor;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> p[i].a >> p[i].b;
        b_coor.emplace_back(p[i].b);
    }

    std::sort(p.begin() , p.end(), [](point i, point j){
        return i.a < j.a;
    });

    std::sort(b_coor.begin() , b_coor.end());
    auto b_pos = [&](int val)->int {
        return std::lower_bound(b_coor.begin() , b_coor.end() , val) - b_coor.begin() + 1;
    };

    BIT Tcount(n), Tsum(n);
    ull total = 0;

    for (int i = 0 ; i < n ; i++) {
        int b_idx = b_pos(p[i].b);

        ull count = Tcount.queryRange(b_idx+1 , n);
        ull sumA = Tsum.queryRange(b_idx+1 , n);

        total += (p[i].a * count) + sumA;

        Tcount.update(b_idx , 1);
        Tsum.update(b_idx , p[i].a);
    }
    std::cout << total;
}