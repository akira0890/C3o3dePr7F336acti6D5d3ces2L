#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <iomanip>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;

    double radian;
    double circlex , circley; std::cin >> circlex >> circley >> radian;

    std::vector<std::pair<double,double>> v(n);
    std::vector<bool> incircle(n , false);
    for (int i = 0 ; i < n ; i++) {
        std::cin >> v[i].first >> v[i].second;
    }

    for (int i = 0 ; i < n ; i++) {
        double dy = std::abs(v[i].second - circley);
        double dx = std::abs(v[i].first - circlex);
        if (dy * dy + dx * dx <= radian * radian) {
            incircle[i] = true;
        }
    }

    std::vector<double> distFromStart(n,0);
    std::vector<double> distFromEnd(n,0);

    for (int i = 1 ; i < n ; i++) {
        distFromStart[i] = std::abs(v[i].first - v[0].first) + std::abs(v[i].second - v[0].second);
    }

    for (int i = 0 ; i < n-1 ; i++) {
        distFromEnd[i] = std::abs(v[i].first - v[n-1].first) + std::abs(v[i].second - v[n-1].second);
    }

    double minstart = LLONG_MAX;
    double minend   = LLONG_MAX;
    for (int i = 1 ; i < n ; i++) {
        if (i > 0   && incircle[i]) minstart = std::min(minstart , distFromStart[i]);
        if (i < n-1 && incircle[i]) minend = std::min(minend , distFromEnd[i]);
    }

    double ansinCircle = minstart + minend;
    double anslinear   = std::abs(v[0].first - v[n-1].first) + std::abs(v[0].second - v[n-1].second);

    if (incircle[0] && incircle[n-1])   std::cout << '0';
    else if (incircle[0])               std::cout << std::fixed << std::setprecision(0) << std::min(anslinear , minend);
    else if (incircle[n-1])             std::cout << std::fixed << std::setprecision(0) << std::min(anslinear , minstart);
    else if (incircle[n-1])             std::cout << std::fixed << std::setprecision(0) << std::min(anslinear , minstart);
    else                                std::cout << std::fixed << std::setprecision(0) << std::min(ansinCircle , anslinear);
}