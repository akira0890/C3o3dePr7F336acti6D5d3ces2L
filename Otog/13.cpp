#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int q,n ,u,v; std::cin >> q;
    
    while (q--) {
        std::cin >> n;
        int maxsleep=0 , mingetup=1e6;
        for (int i = 0 ; i < n ; i++) {
            std::cin >> u >> v;
            maxsleep = std::max(maxsleep , u);
            mingetup = std::min(mingetup , v);
        }
    
        if (maxsleep <= mingetup) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }
    }
}