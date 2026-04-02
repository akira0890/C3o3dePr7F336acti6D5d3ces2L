#pragma one

unsigned long long k = 13;

unsigned long long get_n() {
    return k;
}

bool is_less(unsigned long long Num) {
    return (Num < k);
}

bool is_equal(unsigned long long Num) {
    return (Num == k);
}

void answer(unsigned long long Num) {
    std::cout << Num;
}