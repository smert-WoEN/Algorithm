//
// Created by DenisovDmitrii on 13.03.2023.
//

#include <queue>
#include <cstdio>
#include <list>
#include <iostream>

template <class T, class L>
class reservable_priority_queue : public std::priority_queue < T, std::vector<T>, L >
{
public:
    typedef typename std::priority_queue<T, std::vector<T>, L>::size_type size_type;
    void reserve(size_type capacity)
    {
        this->c.reserve(capacity);
    }
};

class Compare
{
public:
    bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return (a.first == b.first) ? (a.second > b.second) : a.first < b.first;
    }
};

int main()
{
    int n;
    reservable_priority_queue<std::pair<int, int>, Compare> q;
    std::cin >> n;
    q.reserve(n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        q.push(std::make_pair(x, i));
    }
    while(!q.empty())
    {
        auto p1 = q.top(); // Greedily pick the most common sign
        q.pop();
        printf("%d ", p1.second);
        if(!q.empty()) // Make sure we choose another sign next
        {
            auto p2 = q.top();
            q.pop();
            printf("%d ", p2.second);
            if(p2.first > 1)
                q.push(std::make_pair(p2.first - 1, p2.second));
        }
        if(p1.first > 1)
            q.push(std::make_pair(p1.first - 1, p1.second));
    }
    return 0;
}