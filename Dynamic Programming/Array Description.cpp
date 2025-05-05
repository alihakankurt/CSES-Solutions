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

    usize n;
    cin >> n;

    u16 m;
    cin >> m;

    vector<u16> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> nums[index];
    }

    auto dp = vector<vector<u32>>(n, vector<u32>(m + 2, 0));
    if (nums[0] == 0)
    {
        fill(dp[0].begin() + 1, dp[0].end() - 1, 1);
    }
    else
    {
        dp[0][nums[0]] = 1;
    }

    for (usize index = 1; index < n; index += 1)
    {
        u16 num = nums[index];
        if (num == 0)
        {
            for (u16 value = 1; value <= m; value += 1)
            {
                dp[index][value] = (dp[index - 1][value] + dp[index - 1][value - 1] + dp[index - 1][value + 1]) % Modulus;
            }
        }
        else
        {
            dp[index][num] = (dp[index - 1][num] + dp[index - 1][num - 1] + dp[index - 1][num + 1]) % Modulus;
        }
    }

    u32 possibilities = 0;
    for (u16 value = 1; value <= m; value += 1)
    {
        possibilities = (possibilities + dp[n - 1][value]) % Modulus;
    }

    cout << possibilities;

    return 0;
}
