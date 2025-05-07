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

    constexpr u32 MaxN = 1e6 + 17;
    array<array<u64, 2>, MaxN> dp;
    dp[1] = {1, 1};

    for (u32 height = 2; height < MaxN; height += 1)
    {
        dp[height][0] = (2 * dp[height - 1][0] + 1 * dp[height - 1][1]) % Modulus;
        dp[height][1] = (1 * dp[height - 1][0] + 4 * dp[height - 1][1]) % Modulus;
    }

    u16 t;
    cin >> t;
    for (; t > 0; t -= 1)
    {
        u32 n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % Modulus << '\n';
    }

    return 0;
}
