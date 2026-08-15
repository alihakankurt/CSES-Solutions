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

    u16 n, m;
    cin >> n >> m;

    auto edges = vector<pair<u16, u16>>(m);
    auto graph = vector<vector<u16>>(n + 1u);
    auto capacity = vector<vector<u16>>(n + 1u, vector<u16>(n + 1u, 0u));
    for (u16 i = 0u; i < m; ++i)
    {
        u16 a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b] += 1u;
        capacity[b][a] += 1u;
    }

    auto parent = vector<u16>(n + 1u);

    function<u16()> bfs = [&]() {
        fill(parent.begin(), parent.end(), 0u);
        parent[1u] = 1u;

        queue<pair<u16, u16>> qu;
        qu.emplace(1u, numeric_limits<u16>::max());

        while (!qu.empty())
        {
            auto [u, flow] = qu.front();
            qu.pop();

            for (u16 v : graph[u])
            {
                if (parent[v] == 0u && capacity[u][v] > 0u)
                {
                    parent[v] = u;
                    u16 nflow = min(flow, capacity[u][v]);
                    if (v == n) return nflow;
                    qu.emplace(v, nflow);
                }
            }
        }

        return static_cast<u16>(0u);
    };

    u16 answer = 0u;
    while (u16 flow = bfs())
    {
        answer += flow;
        u16 v = n;
        while (v != 1u)
        {
            u16 u = parent[v];
            capacity[u][v] -= flow;
            capacity[v][u] += flow;
            v = u;
        }
    }

    queue<u16> qu;
    auto reachable = vector<u8>(n + 1u, 0u);

    qu.emplace(1u);
    reachable[1u] = 1u;
    while (!qu.empty())
    {
        auto u = qu.front();
        qu.pop();

        for (u16 v : graph[u])
        {
            if (!reachable[v] && capacity[u][v] > 0u)
            {
                reachable[v] = 1u;
                qu.emplace(v);
            }
        }
    }

    cout << answer << '\n';
    for (auto [u, v] : edges)
    {
        if (reachable[u] != reachable[v])
        {
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}
