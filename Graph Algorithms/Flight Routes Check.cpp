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

    auto forward = vector<vector<u32>>(n + 1);
    auto backward = vector<vector<u32>>(n + 1);
    while (m--)
    {
        u32 a, b;
        cin >> a >> b;
        forward[a].push_back(b);
        backward[b].push_back(a);
    }

    auto vis = vector<bool>(n + 1);
    function<void(u32, const vector<vector<u32>>&)> dfs = [&](auto u, auto& graph) {
        vis[u] = true;
        for (u32 v : graph[u])
        {
            if (!vis[v])
            {
                dfs(v, graph);
            }
        }
    };

    fill(vis.begin(), vis.end(), false);
    dfs(1, forward);
    for (u32 u = 2; u <= n; ++u)
    {
        if (!vis[u])
        {
            cout << "NO" << '\n';
            cout << 1 << ' ' << u;
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);
    dfs(1, backward);
    for (u32 u = 2; u <= n; ++u)
    {
        if (!vis[u])
        {
            cout << "NO" << '\n';
            cout << u << ' ' << 1;
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
