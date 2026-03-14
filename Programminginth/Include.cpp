#include <iostream>
#include <vector>

int main() {
    int n,temp,t;
    std::cin >> n;

    std::vector<std::vector<int>> file(n);
    int includesum[n] = {0};
    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        while (t--) {
            std::cin >> temp;
            file[i].emplace_back(temp);
            for (int in : file[temp-1]) includesum[in-1]++,std::cout << in-1 << ' ';
            std::cout << '\n';
        }
    }

    for (int i = 0 ; i < n ; i++) {
        std::cout << includesum[i] << ' ';
        if (includesum[i] > 1) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}