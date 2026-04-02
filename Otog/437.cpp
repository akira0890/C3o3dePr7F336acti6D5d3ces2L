#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long a,b,c;
    while (std::cin >> a >> b >> c) {
        long long res = 1;
        while (b) {
            if (b & 1) { 
                res = (res * a) % c;
                b--;
            } else {
                a = (a*a) % c;
                b /= 2;
            }
        }
    
        std::cout << res << '\n';
    }
}