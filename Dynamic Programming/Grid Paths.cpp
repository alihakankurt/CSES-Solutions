#include <bits/stdc++.h>
using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f32 = float_t;
using f64 = double_t;

inline constexpr i32 Modulus = 1e9 + 7;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 n;
    cin >> n;

    vector<string> grid(n);
    for (u16 y = 0; y < n; y += 1)
    {
        cin >> grid[y];
    }

    auto dp = vector<vector<u32>>(n + 1, vector<u32>(n + 1, 0));
    dp[0][1] = 1;

    for (u16 y = 1; y <= n; y += 1)
    {
        for (u16 x = 1; x <= n; x += 1)
        {
            if (grid[y - 1][x - 1] == '.')
            {
                dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % Modulus;
            }
        }
    }

    cout << dp[n][n];

    return 0;
}
