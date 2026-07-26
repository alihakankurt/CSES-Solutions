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

    constexpr u32 log = 30;
    auto tps = vector<vector<u32>>(n + 1, vector<u32>(log));

    for (u32 p = 1; p <= n; ++p)
    {
        u32 t;
        cin >> t;
        tps[p][0] = t;
    }

    for (u32 i = 1; i < log; ++i)
    {
        for (u32 p = 1; p <= n; ++p)
        {
            tps[p][i] = tps[tps[p][i - 1]][i - 1];
        }
    }

    while (q--)
    {
        u32 x, k;
        cin >> x >> k;

        for (u32 i = 0; i < log; ++i)
        {
            if (k & (1u << i))
            {
                x = tps[x][i];
            }
        }

        cout << x << ' ';
    }

    return 0;
}
