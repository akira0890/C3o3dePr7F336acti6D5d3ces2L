#include <iostream>

#define FOR(X) for (int i = 0 ; i < X ; i++)
#define STRING(X,Y) std::string(X,Y)

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    FOR(n) std::cout << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << '\n';
    FOR(n) std::cout << STRING(n*2,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << STRING(n*3,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << '\n';
    FOR(n) std::cout << STRING(n*3,'#') << STRING(n,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << '\n';
    FOR(n) std::cout << STRING(n,'#') << STRING(n*3,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << STRING(n,' ')  << STRING(n,'#') << STRING(n*3,' ') << STRING(n,'#') << STRING(n,' ') << STRING(n,'#') << '\n';
    FOR(n) std::cout << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << STRING(n,' ') << STRING(n*3,'#') << '\n';
}