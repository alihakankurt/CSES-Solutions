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

    auto graph = vector<vector<u32>>(n + 1);
    auto indegree = vector<u32>(n + 1);

    while (m--)
    {
        u32 a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ++indegree[b];
    }

    queue<u32> qu;
    for (u32 u = 1; u <= n; ++u)
    {
        if (indegree[u] == 0)
        {
            qu.emplace(u);
        }
    }

    auto dp = vector<u64>(n + 1);
    dp[1] = 1;

    while (!qu.empty())
    {
        auto u = qu.front();
        qu.pop();

        for (u32 v : graph[u])
        {
            dp[v] = (dp[v] + dp[u]) % Modulus;
            if (--indegree[v] == 0)
            {
                qu.emplace(v);
            }
        }
    }

    cout << dp[n];

    return 0;
}
