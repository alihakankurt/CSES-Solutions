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

    auto flights = vector<vector<pair<u32, u32>>>(cityCount + 1);
    while (flightCount--)
    {
        u32 startingCity, endingCity, flightLength;
        cin >> startingCity >> endingCity >> flightLength;
        flights[startingCity].emplace_back(endingCity, flightLength);
    }

    auto distances = vector<u64>(cityCount + 1, numeric_limits<u64>::max());
    auto qu = priority_queue<pair<u64, u32>, vector<pair<u64, u32>>, greater<>>();

    constexpr u32 TargetCity = 1;
    distances[TargetCity] = 0;
    qu.emplace(0, TargetCity);

    while (!qu.empty())
    {
        auto [distance, city] = qu.top();
        qu.pop();

        if (distance > distances[city])
            continue;

        for (auto [flightCity, flightCost] : flights[city])
        {
            u64 totalDistance = distance + flightCost;
            if (totalDistance < distances[flightCity])
            {
                distances[flightCity] = totalDistance;
                qu.emplace(totalDistance, flightCity);
            }
        }
    }

    for (u32 city = 1; city <= cityCount; ++city)
    {
        cout << distances[city] << ' ';
    }

    return 0;
}
