#include <iostream>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s;
    int k,n=0;
    std::cin >> s >> k;

    for (int i = 0 ; i < s.length()-1 ; i++) {
        if ((s[i]=='c'||s[i]=='C') && (s[i+1]=='c'||s[i+1]=='C')) n++;
    }

    if (n >= k) {
        std::cout << "#OCOMisfun";
        for (int i = 0 ; i < n-k ; i++) std::cout << " fun";
    } else {
        std::cout << "OCOM is not fun";
    }
}