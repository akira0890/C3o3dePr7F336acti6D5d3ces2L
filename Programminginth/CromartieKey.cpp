#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,m;
    std::cin >> n >> m;

    std::string a,b,key;
    std::cin >> a >> b >> key;

    for (int i = 0 ; i < m ; i++) {
        char k = key[i];
        for (int j = 0 ; j < n ; j++) {
            char x = a[j], y = k, z = b[j];

            if (x > y) std::swap(x,y);
            if (y > z) std::swap(y,z);
            if (x > y) std::swap(x,y);

            k = y;
        }
        std::cout << k;
    }
}