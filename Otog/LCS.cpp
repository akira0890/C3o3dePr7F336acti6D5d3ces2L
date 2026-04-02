#include <iostream>
#include <vector>

long long memo[1000][1000];
std::string a,b;
int recursive(int i , int j) {
    if (i < 0 || j < 0) return 0;
    if (memo[i][j]) return memo[i][j];
    
    int res = 0;
    if (a[i] != b[j]) {
        res += std::max(recursive(i-1 , j) , recursive(i , j-1));
    } else {
        res += 1 + recursive(i-1,j-1);
    }

    return memo[i][j] = res;
}

int main() {
    std::cin >> a >> b;
    std::cout << recursive(a.length()-1 , b.length()-1) << ' ' << std::max(a.length() , b.length());
}