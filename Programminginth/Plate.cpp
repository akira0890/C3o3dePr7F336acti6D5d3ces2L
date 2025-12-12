#include <iostream>
#include <queue>

int level[10001];
bool hasclass[11];

int main() {
    int c,n,le,hash,id;
    std::cin >> c >> n;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> le >> hash;
        level[hash] = le;
    }

    std::queue<int> q;
    std::queue<int> classq[11];

    char cmd;
    while (std::cin >> cmd && cmd != 'X') {
        if (cmd == 'E') {
            std::cin >> id;

            int classlevel = level[id];
            if (!hasclass[classlevel]) {
                q.push(id);
                hasclass[classlevel] = true;
            }

            classq[classlevel].push(id);

        } else {
            if (q.empty()) {
                std::cout << "empty\n";
            } else {
                int firstlevel = level[q.front()];
                int first = classq[firstlevel].front();
                std::cout << first << '\n';

                classq[firstlevel].pop();

                // accord to if there is people in same class in the queue, new person would be at the back of that person with the same class so it continuous if there no people in same class in the queue then pop it from the queue
                if (classq[firstlevel].empty()) {
                    q.pop();
                    hasclass[firstlevel] = false;
                }
            }
        }
    }
    std::cout << '0';
}