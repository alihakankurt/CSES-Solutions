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

    constexpr u16 INF = numeric_limits<u16>::max();

    u16 n, m, k;
    cin >> n >> m >> k;

    auto graph = vector<vector<u16>>(n + m + 1u);
    while (k--)
    {
        u16 a, b;
        cin >> a >> b;
        b += n;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto depth = vector<u16>(n + 1u, 0u);
    auto match = vector<u16>(n + m + 1u, 0u);

    function<bool(u16)> dfs = [&](auto u) -> bool {
        if (u == 0u)
        {
            return true;
        }

        for (u16 v : graph[u])
        {
            if (depth[match[v]] == depth[u] + 1u && dfs(match[v]))
            {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }

        depth[u] = INF;
        return false;
    };

    u16 pairs = 0u;
    for (;;)
    {
        queue<u16> qu;

        depth[0u] = INF;
        for (u16 u = 1u; u <= n; ++u)
        {
            if (match[u] == 0u)
            {
                depth[u] = 0u;
                qu.emplace(u);
            }
            else
            {
                depth[u] = INF;
            }
        }

        while (!qu.empty())
        {
            auto u = qu.front();
            qu.pop();

            if (depth[u] >= depth[0u])
            {
                break;
            }

            for (u16 v : graph[u])
            {
                if (depth[match[v]] == INF)
                {
                    depth[match[v]] = depth[u] + 1u;
                    qu.emplace(match[v]);
                }
            }
        }

        if (depth[0u] == INF)
        {
            break;
        }

        for (u16 u = 1u; u <= n; ++u)
        {
            if (match[u] == 0u && dfs(u))
            {
                ++pairs;
            }
        }
    }

    cout << pairs << '\n';
    for (u16 u = 1u; u <= n; ++u)
    {
        if (match[u] > 0u)
        {
            cout << u << ' ' << (match[u] - n) << '\n';
        }
    }

    return 0;
}
