#include <bits/stdc++.h>
using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using uptr = uintptr_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = make_signed_t<size_t>;
using iptr = intptr_t;

using f32 = float_t;
using f64 = double_t;

constexpr i32 Modulus = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 cityCount, flightCount;
    cin >> cityCount >> flightCount;

    auto flightGraph = vector<vector<pair<u32, u32>>>(cityCount + 1);
    while (flightCount--)
    {
        u32 start, end, price;
        cin >> start >> end >> price;
        flightGraph[start].emplace_back(end, price);
    }

    auto distance = vector<array<u64, 2>>(cityCount + 1, {numeric_limits<u64>::max(), numeric_limits<u64>::max()});
    distance[1][0] = 0;

    priority_queue<pair<u64, pair<u32, u32>>, vector<pair<u64, pair<u32, u32>>>, greater<>> qu;
    qu.push({0, {1, false}});

    while (!qu.empty())
    {
        auto [currentPrice, state] = qu.top();
        auto [start, discounted] = state;
        qu.pop();

        if (currentPrice > distance[start][discounted])
        {
            continue;
        }

        for (auto [end, price] : flightGraph[start])
        {
            if (!discounted && distance[end][0] > currentPrice + price)
            {
                distance[end][0] = currentPrice + price;
                qu.push({distance[end][0], {end, false}});
            }

            if (!discounted && distance[end][1] > currentPrice + price / 2)
            {
                distance[end][1] = currentPrice + price / 2;
                qu.push({distance[end][1], {end, true}});
            }

            if (discounted && distance[end][1] > currentPrice + price)
            {
                distance[end][1] = currentPrice + price;
                qu.push({distance[end][1], {end, true}});
            }
        }
    }

    u64 answer = distance.back()[1];
    cout << answer;

    return 0;
}
