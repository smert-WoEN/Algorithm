//
// Created by DenisovDmitrii on 26.02.2023.
//

#include <iostream>
#include<algorithm>


struct point {
    int64_t x;
    int64_t y;
    int64_t id;
};

struct point* points;

bool compare(struct point a, struct point b) {
    return (a.x - points[0].x) * (b.y - points[0].y)
    - (b.x - points[0].x) * (a.y - points[0].y) > 0;
}

int main() {
    int n;
    std::cin >> n;
    points = (struct point*) (malloc(n * sizeof(point)));
    std::cin >> points[0].x >> points[0].y;
    points[0].id = 0;
    for (int i = 1; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i;
        if (points[i].x < points[0].x ||
        points[i].x == points[0].x &&
        points[i].y < points[0].y) std::swap(points[0], points[i]);
    }
    std::nth_element(points + 1, points + n / 2, points + n, compare);
    std::cout << points[0].id + 1 << " " << points[n / 2].id + 1;

}
