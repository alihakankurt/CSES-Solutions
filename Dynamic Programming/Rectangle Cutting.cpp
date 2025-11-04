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

    u16 width, height;
    cin >> width >> height;

    auto dp = vector<vector<u32>>(width + 1, vector<u32>(height + 1, numeric_limits<u32>::max()));

    for (u16 w = 1; w <= width; w += 1)
    {
        for (u16 h = 1; h <= height; h += 1)
        {
            if (w == h)
            {
                dp[w][h] = 0;
                continue;
            }

            for (u16 c = 1; c < w; c += 1)
            {
                dp[w][h] = min(dp[w][h], dp[c][h] + dp[w - c][h] + 1);
            }

            for (u16 c = 1; c < h; c += 1)
            {
                dp[w][h] = min(dp[w][h], dp[w][c] + dp[w][h - c] + 1);
            }
        }
    }

    cout << dp[width][height];

    return 0;
}
