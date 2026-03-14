#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,q,l,r; std::cin >> n >> q;
    std::vector<int> v(n), temp;

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    while (q--) {
        std::cin >> l >> r;

        temp = v;
        std::sort(temp.begin()+l , temp.begin()+r+1);

        for (int i = l ; i <= r ; i++) std::cout << temp[i] << ' '; std::cout << '\n';
    }
}