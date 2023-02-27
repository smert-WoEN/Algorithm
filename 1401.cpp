//
// Created by DenisovDmitrii on 26.02.2023.
//

#include <iostream>

int m = 3, A[512][512];


void generate_plot(int n, int x, int y, int hx, int hy)
{
    if(n == 2)
    {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                if(x + i != hx || y + j != hy)
                    A[x + i][y + j] = m++ / 3;
        return;
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(x + i * n / 2 > hx || hx >= x + i * n / 2 + n / 2 || y + j * n / 2 > hy || hy >= y + j * n / 2+n / 2)
                A[x + n / 2 - 1 + i][y + n / 2 - 1 + j] = m++ / 3;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(x + i * n / 2 <= hx && hx < x + i * n / 2 + n / 2 && y + j * n / 2 <= hy && hy < y + j * n / 2 + n / 2)
                generate_plot(n / 2, x + i * n / 2, y + j * n / 2, hx, hy);
            else
                generate_plot(n / 2, x + i * n / 2, y + j * n / 2, x + n / 2 - 1 + i, y + n / 2 - 1 + j);
}

int main()
{
    int n, px, py;
    std::cin >> n >> px >> py;
    int s = [] (int n) { int i = 1; while(n--) i*=2; return i; }(n);
    generate_plot(s, 0, 0, px - 1, py - 1);
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }
}
