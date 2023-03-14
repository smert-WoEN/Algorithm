//
// Created by DenisovDmitrii on 13.03.2023.
//

#include <vector>
#include <iostream>

std::vector<int> s[256];
char in[100001];
int n[100000], f, p = 0;

int main()
{
    std::cin >> f >> in;
    for(int i = 0; in[i]; i++)
        s[in[i]].push_back(i);
    std::cout << s << std::endl;
    for(auto & i : s)
        for(auto q : i)
            n[p++] = q;
    for(int i = 0, x = f-1; i < p; i++)
        putchar(in[x = n[x]]);
    return 0;
}
