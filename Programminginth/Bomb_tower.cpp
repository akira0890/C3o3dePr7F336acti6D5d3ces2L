#include <iostream>
#include <cstring>

int main() {
    int n,curr,want=1; // count 2
    std::cin >> n >> curr;

    bool isprime[n/2];
    std::memset(isprime, 0, sizeof(isprime));

    for (int i = 3 ; i*i < n ; i+=2) {
        if (isprime[i/2] == false)
            for (int j = i*i ; j < n ; j+= i*2)
                isprime[j/2] = true;
    }

    for (int i = 3 ; i < n ; i+=2) {
        if (isprime[i/2] == false) want++;
    }

    int res = want-curr;
    if (res < 0) {
        std::cout << 0;
        return 0;
    }
    std::cout << want - curr;
}