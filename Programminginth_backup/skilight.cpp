#include <iostream>
#include <cmath>

int main() {
    int n,m;
    int fuseprice, time, person,temp;

    std::cin >> n >> m >> fuseprice >> time >> person;
    double sum  = fuseprice * time * person;
    for (int i = 0 ; i < n*m ; i++) std::cin >> temp , sum+=temp;

    std::cout << (long long)std::ceil(sum/person);
}