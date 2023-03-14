//
// Created by DenisovDmitrii on 13.03.2023.
//

#include <iostream>
#include <algorithm>
#include <cmath>

struct point {
    int x, y;
    int i;
} p[30000];

int f(point& a, point& b) {
    if(a.x*b.y == a.y*b.x && a.x*b.x + a.y*b.y >= 0)
        return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

int main() {
    int n;
    std::ios::sync_with_stdio(false);
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        std::cin >> p[i].x >> p[i].y;
        p[i].i = i;
    }

    for(int i = n-1; i >= 0; i--)
        p[i].x -= p[0].x, p[i].y -= p[0].y;

    std::sort(p, p+n, f);

    int s = 0;
    for(int i = 0; i < n-1; i++) {
        point p0 = p[0], p1 = p[i], p2 = p[i+1];
        int d1x = p1.x-p0.x, d2y = p2.y-p0.y, d1y = p1.y-p0.y, d2x = p2.x-p0.x;
        int x = d1x*d2y - d1y*d2x, d = d1x*d2x + d1y*d2y;
        if(x < 0 || x == 0 && d < 0) {
            s = i;
            break;
        }
    }

    std::cout << n << std::endl;
    std::cout << (p[0].i+1) << std::endl;
    for(int i = 0; i < n-1; i++)
        std::cout << (p[(s+i)%(n-1)+1].i+1) << std::endl;
    return 0;
}