#include <iostream>
#include <algorithm>

// this code is for solve bus stop problem
static int array[100000];

inline int gcd(int A, int B) {
    while (B) {
        A %= B;
        std::swap(A,B);
    }
    return A;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    unsigned long long lcm;
    
    std::cin >> n >> array[0];
    lcm = array[0];

    for (int i = 1 ; i < n ; i++) {
        std::cin >> array[i];
        lcm = (lcm * array[i]) / gcd(array[i] , lcm);
    }

    std::cout << lcm;
}