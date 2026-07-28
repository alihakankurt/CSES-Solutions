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

    u32 n;
    cin >> n;

    auto tps = vector<u32>(n + 1);

    for (u32 p = 1; p <= n; ++p)
    {
        u32 t;
        cin >> t;
        tps[p] = t;
    }

    auto dist = vector<u32>(n + 1, 0);
    auto ans = vector<u32>(n + 1, 0);

    function<u32(u32, u32)> dfs = [&](u32 p, u32 d) {
        dist[p] = d;
        u32 t = tps[p];

        if (dist[t] == 0u)
        {
            u32 c = dfs(tps[p], d + 1);
            if (c == 0u)
            {
                ans[p] = ans[t] + 1;
                return 0u;
            }

            ans[p] = ans[t];
            return (p == c) ? 0u : c;
        }

        if (ans[t] == 0u)
        {
            ans[p] = dist[p] - dist[t] + 1;
            return (p == t) ? 0u : t;
        }

        ans[p] = ans[t] + 1;
        return 0u;
    };

    for (u32 p = 1; p <= n; ++p)
    {
        if (dist[p] == 0u)
        {
            dfs(p, 1u);
        }

        cout << ans[p] << ' ';
    }

    return 0;
}
