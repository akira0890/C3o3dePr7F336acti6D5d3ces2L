#include <iostream>

#define forN(x) for (int i = 0 ; i < x ; i++)
#define Sd(x) std::string(x,'.')
#define Ssh(x) std::string(x,'#')

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    forN(n) std::cout << Sd(25*n) << '\n';
    forN(n) std::cout << Sd(2*n) << Ssh(3*n) << Sd(2*n) << Ssh(5*n) << Sd(2*n) << Ssh(3*n) << Sd(3*n) << Ssh(4*n) << Sd(n) << '\n';
    forN(n) std::cout << Sd(n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(n) << Ssh(n) << Sd(5*n) << '\n';
    forN(n) std::cout << Sd(n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(n) << Ssh(n) << Sd(n) << Ssh(3*n) << Sd(n) << '\n';
    forN(n) std::cout << Sd(n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(n) << Ssh(n) << Sd(3*n) << Ssh(n) << Sd(n) << '\n';
    forN(n) std::cout << Sd(2*n) << Ssh(3*n) << Sd(4*n) << Ssh(n) << Sd(4*n) << Ssh(3*n) << Sd(3*n) << Ssh(3*n) << Sd(2*n) << '\n';
    forN(n) std::cout << Sd(25*n) << '\n';
}

/*
         1111111111222222
1234567890123456789012345
0000000000000000000000000
0011100111110011100011110
0011100111110011100010110
0011100111110011100011110
0011100111110011100011100
0000000000000000000000000
*/