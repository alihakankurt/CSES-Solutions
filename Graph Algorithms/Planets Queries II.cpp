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

    u32 n, q;
    cin >> n >> q;

    constexpr u32 log = 18;
    auto tps = vector<vector<u32>>(n + 1, vector<u32>(log));

    for (u32 p = 1; p <= n; ++p)
    {
        u32 t;
        cin >> t;
        tps[p][0] = t;
    }

    auto len = vector<u32>(n + 1, numeric_limits<u32>::max());

    function<void(u32)> dfs = [&](u32 p) {
        if (len[p] != numeric_limits<u32>::max()) return;
        len[p] = 0;

        dfs(tps[p][0]);

        len[p] = len[tps[p][0]] + 1;

        for (u32 i = 1; i < log; ++i)
        {
            tps[p][i] = tps[tps[p][i - 1]][i - 1];
        }
    };

    for (u32 p = 1; p <= n; ++p)
    {
        if (len[p] == numeric_limits<u32>::max())
        {
            dfs(p);
        }
    }

    function<u32(u32, u32)> travel = [&](u32 p, u32 k) {
        if (k > n) return p;

        for (u32 i = 0; i < log; ++i)
        {
            if (k & (1u << i))
            {
                p = tps[p][i];
            }
        }

        return p;
    };

    while (q--)
    {
        u32 a, b, c;
        cin >> a >> b;
        c = travel(a, len[a]);

        i32 ans = -1;
        if (travel(a, len[a] - len[b]) == b)
        {
            ans = len[a] - len[b];
        }
        else if (travel(c, len[c] - len[b]) == b)
        {
            ans = len[c] - len[b] + len[a];
        }

        cout << ans << ' ';
    }

    return 0;
}
