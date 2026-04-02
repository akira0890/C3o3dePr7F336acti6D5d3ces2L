#include <iostream>
#include <vector>

long long MOD = 10;

struct BigInt {
    
}

int main() {
    std::vector<long long> v(100,1);
    v[0] = 0;
    
    for (int i  = 5 ; i < 100 ; i++) {
        v[i] = v[i-4]+v[i-3]+v[i-2]+v[i-1];
        v[i] %= 10;
    }

    for (int i = 1 ; i < 100 ; i++) {
        std::cout << v[i] << ' ';
    }
}