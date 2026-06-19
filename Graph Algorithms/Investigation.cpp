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

    u32 n, m;
    cin >> n >> m;

    auto graph = vector<vector<pair<u32, u32>>>(n + 1);

    while (m--)
    {
        u32 a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    auto qu = priority_queue<pair<u64, u32>, vector<pair<u64, u32>>, greater<>>();
    auto distance = vector<u64>(n + 1, numeric_limits<u64>::max());
    auto paths = vector<u64>(n + 1, 0);
    auto minFlightPath = vector<u32>(n + 1, 0);
    auto maxFlightPath = vector<u32>(n + 1, 0);

    qu.emplace(0, 1);
    distance[1] = 0;
    paths[1] = 1;

    while (!qu.empty())
    {
        auto [dist, u] = qu.top();
        qu.pop();

        if (dist > distance[u])
            continue;

        for (auto [v, c] : graph[u])
        {
            u64 cost = distance[u] + c;

            if (distance[v] > cost)
            {
                distance[v] = cost;
                paths[v] = paths[u];
                minFlightPath[v] = minFlightPath[u] + 1;
                maxFlightPath[v] = maxFlightPath[u] + 1;
                qu.emplace(cost, v);
            }
            else if (distance[v] == cost)
            {
                paths[v] = (paths[v] + paths[u]) % Modulus;
                minFlightPath[v] = min(minFlightPath[v], minFlightPath[u] + 1);
                maxFlightPath[v] = max(maxFlightPath[v], maxFlightPath[u] + 1);
            }
        }
    }

    cout << distance[n] << ' ' << paths[n] << ' ' << minFlightPath[n] << ' ' << maxFlightPath[n];

    return 0;
}
