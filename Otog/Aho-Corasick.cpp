#include <iostream>
#include <vector>
#include <queue>

#define MAX 26

struct Node {
    int next[MAX];
    int fail;
    int count;

    Node () {
        for (int i = 0 ; i < MAX ; i++) next[i] = 0;
        fail = 0;
        count = 0;
    }
};

class AhoCorasick {
    std::vector<Node> tries;
public:
    AhoCorasick() {
        tries.emplace_back();
    }
    void insert(const std::string& pattern) {
        int curr = 0;
        for (char c : pattern) {
            int idx = c - 'a';
            if (!tries[curr].next[idx]) {
                tries[curr].next[idx] = tries.size();
                tries.emplace_back();
            }
            curr = tries[curr].next[idx];
        }
        tries[curr].count++;
    }

    void build() {
        std::queue<int> q;
        for (int i = 0 ; i < MAX ; i++) {
            if (tries[0].next[i]) {
                q.emplace(tries[0].next[i]);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0 ; i < MAX ; i++) {
                int v = tries[u].next[i];
                if (v) {
                    tries[v].fail = tries[tries[u].fail].next[i];
                    tries[v].count += tries[tries[v].fail].count;
                    q.emplace(v);
                } else {
                    tries[u].next[i] = tries[tries[u].fail].next[i];
                }
            }
        }
    }

    int search(const std::string& word) {
        int ans = 0;
        int curr = 0;
        for (char c : word) {
            curr = tries[curr].next[c - 'a'];
            ans += tries[curr].count;
        }
        return ans;
    }
};

int main() {
    std::vector<std::string> pattern = {"he", "she", "his", "hers"};

    AhoCorasick ac;
    for (const std::string& p : pattern) {
        ac.insert(p);
    }

    ac.build();

    std::string word = "ushers";
    std::cout << ac.search(word) << '\n';
}