#include <iostream>
#include <vector>

std::vector<int> coin;
long long memo[105][10'000];
int sum , n;

int recursive(int idx , int curr) {
    if (curr == 0) return 1;
    if (idx >= n || curr < 0)  return 0;
    // แนะนำให้ใช้ กำหนดค่าเริ่มต้นเป็น -1 แล้ว memo[idx][curr] != -1
    if (memo[idx][curr]) return memo[idx][curr];
    
    return memo[idx][curr] = recursive(idx , curr - coin[idx]) + recursive(idx+1 , curr);
}

int main() {
    std::cin >> sum >> n;
    coin.resize(n);

    for (int i = 0 ; i < n ; i++) std::cin >> coin[i];
    memo[0][0] = 1;

    std::cout << recursive(0,sum) << ' ';
    
    std::vector<int> memo2(100'000,0);
    memo2[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int price = coin[i] ; price <= sum ; price++) {
            memo2[price] += memo2[price - coin[i]];
        }
    }

    std::cout << memo2[sum];
}
