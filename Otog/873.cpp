#include <iostream>
#include <vector>

inline void update(std::vector<int> &v, int index) {
    index++;
    for (int i = index ; i <= v.size() ; i += i & -i) {
        v[i]++;
    }
}

inline int query(std::vector<int> &v , int index) {
    int sum = 0;
    index++;
    for (int i = index ; i > 0 ; i -= i & -i) {
        sum += v[i];
    }
    return sum;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,t; std::cin >> n;
    std::vector<int> v(1000005,0);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        std::cout << query(v , t) << ' ';
        update(v,t);
    }
}