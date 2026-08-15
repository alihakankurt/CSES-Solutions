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

    auto graph = vector<vector<u32>>(n + 1u);
    while (m--)
    {
        u32 a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
    }

    u32 limit = 1u << n;
    auto dp = vector<vector<u32>>(limit, vector<u32>(n, 0u));

    dp[1u << 0u][0u] = 1u;

    for (u32 state = 0u; state < limit; ++state)
    {
        for (u32 u = 0u; u < n; ++u)
        {
            u64 routes;
            if (routes = dp[state][u]; routes == 0u || (state & (1u << u)) == 0u)
            {
                continue;
            }

            for (u32 v : graph[u])
            {
                u32 next = state | (1u << v);
                if (next == state) continue;
                dp[next][v] = (dp[next][v] + routes) % Modulus;
            }
        }
    }

    cout << dp[limit - 1u][n - 1u];

    return 0;
}
