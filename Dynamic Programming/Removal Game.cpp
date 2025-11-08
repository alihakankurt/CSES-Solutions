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

    i64 sum = 0;
    vector<i32> x(n);
    auto dp = vector<vector<i64>>(n, vector<i64>(n, 0));
    for (u16 index = 0; index < n; index += 1)
    {
        i32 num;
        cin >> num;
        sum += num;
        x[index] = num;
        dp[index][index] = num;
    }

    for (u16 left = n - 2; left < n; left -= 1)
    {
        for (u16 right = left + 1; right < n; right += 1)
        {
            dp[left][right] = max(x[left] - dp[left + 1][right], x[right] - dp[left][right - 1]);
        }
    }

    i64 answer = (sum + dp[0][n - 1]) / 2;
    cout << answer;

    return 0;
}
