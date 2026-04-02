#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q; std::cin >> q;

    for (int i = 0 ; i < q ; i++) {
        int size ;
        std::cin >> size;

        std::vector<int> v(size);

        for (int i = 0 ; i < size ; i++) std::cin >> v[i];
        std::vector<int> sorted = v;

        std::sort(sorted.begin() , sorted.end());

        int ans = 0 , iter = size-1;
        for (int i = size-1 ; i >= 0 ; i--) {
            if (sorted[iter] == v[i]) {
                iter--;
            } else {
                ans++;
            }
        }

        std::cout << ans << '\n';
    }
}