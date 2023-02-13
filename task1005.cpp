//
// Created by DmitriiDenisov on 07.02.2023.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int diff = INT_MAX;
    int w[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    int limit = 2 << (n - 1);
    for (int i = 0; i < limit; ++i) {
        int sum1 = 0;
        int sum2 = 0;
        int k = i;
        for (int j = 0; j < n; ++j) {
            if ((k & 0x1) == 0) {
                sum1 += w[j];
            } else {
                sum2 += w[j];
            }
            k = k >> 1;
        }
        diff = std::min(diff, abs(sum2 - sum1));
    }
    std::cout << diff;
    return 0;
}