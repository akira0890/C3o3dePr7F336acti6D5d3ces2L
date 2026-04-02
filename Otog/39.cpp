#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k,l; std::cin >> n >> k >> l;

    std::vector<int> v(n);
    for (int i = 0 ; i < n ; i++) v[i] = i+1;

    int curr = 1;
    while (std::next_permutation(v.begin() , v.end())) {
        curr++;
        if (curr == l) break;
    }

    for (int i = 0 ; i < k ; i++) {
        std::cout << v[i] << ' ';
    }
}