#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<int> v(n) , forbid(m);
    std::vector<bool> ca(n , true);

    for (int i = 1 ; i <= n ; i++) v[i-1] = i;

    for (int i = 0 ; i < m ; i++) std::cin >> forbid[i] , ca[forbid[i] - 1] = false;

    for (int f : v) {
        if (!ca[f-1]) continue;
        v.erase(v.begin() + f - 1);
        do {
            std::printf("%d",f);
            for (int in : v) {
                std::printf(" %d",in);
            }
            std::printf("\n");
        } while (std::next_permutation(v.begin() , v.end()));
        v.emplace_back(f);
        std::sort(v.begin() , v.end());
    }
}