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

    u32 cityCount, roadCount, queryCount;
    cin >> cityCount >> roadCount >> queryCount;

    constexpr u64 maxDistance = numeric_limits<u64>::max() / 2;
    auto distances = vector<vector<u64>>(cityCount + 1, vector<u64>(cityCount + 1, maxDistance));

    while (roadCount--)
    {
        u32 city1, city2, length;
        cin >> city1 >> city2 >> length;

        if (length < distances[city1][city2])
        {
            distances[city1][city2] = length;
            distances[city2][city1] = length;
        }
    }

    for (u32 city = 1; city <= cityCount; ++city)
    {
        distances[city][city] = 0;
    }

    for (u32 middle = 1; middle <= cityCount; ++middle)
    {
        for (u32 start = 1; start <= cityCount; ++start)
        {
            for (u32 end = 1; end <= cityCount; ++end)
            {
                distances[start][end] = min(distances[start][end], distances[start][middle] + distances[middle][end]);
            }
        }
    }

    while (queryCount--)
    {
        u32 city1, city2;
        cin >> city1 >> city2;

        i64 distance = distances[city1][city2];
        cout << ((distance == maxDistance) ? -1 : distance) << '\n';
    }

    return 0;
}
