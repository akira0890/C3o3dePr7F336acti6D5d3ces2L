#include <iostream>
#include <queue>
#include <map>

struct Node {
    int h,d,index;

    Node (int H, int D, int i) : h(H) , d(D) , index(i) {}

    bool operator<(const Node& other) const {
        return h < other.h;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,h,d; std::cin >> n;
    std::priority_queue<Node> pq;
    std::map<int, int> hp_count;
    
    long long sum = 0 , curr = 0;
    long long sumdamage = 0;
    for (int i = 1 ; i <= n ; i++) {
        std::cin >> h >> d;
        if (h >= 10 && hp_count[h] == 0) {
            sumdamage += d;
            pq.emplace(h,d,i);
            hp_count[h]++;
        }
    }

    while (!pq.empty()) {
        sum += sumdamage;

        int heal = pq.top().h;
        int damage = pq.top().d;
        int index = pq.top().index;
        pq.pop();
        hp_count[heal]--;

        heal /= 2;
        curr = index;

        if (hp_count[heal] == 0 && heal >= 10) {
            pq.emplace(heal,damage,index);
            hp_count[heal]++;
        } else {
            sumdamage -= damage;
        }
    }

    std::cout << sum << ' ' << curr;
}