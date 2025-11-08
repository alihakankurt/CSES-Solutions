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

template <typename TBase, typename TExponent, typename TModulus>
inline constexpr TBase ModPow(TBase base, TExponent exponent, TModulus modulus)
{
    TBase modulus_ = static_cast<TBase>(modulus);
    base %= modulus_;
    TBase result = 1;
    while (exponent > 0)
    {
        if ((exponent & 1) == 1)
            result = (result * base) % modulus_;

        base = (base * base) % modulus_;
        exponent >>= 1;
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 n;
    cin >> n;

    u32 sum = n * (n + 1) / 2;
    if ((sum & 1) == 1)
    {
        cout << '0';
        return 0;
    }

    u32 halfSum = sum / 2;
    vector<u32> dp(halfSum + 1, 0);
    dp[0] = 1;

    for (u16 num = 1; num <= n; num += 1)
    {
        for (u32 currentSum = halfSum; currentSum >= num; currentSum -= 1)
        {
            dp[currentSum] = (dp[currentSum] + dp[currentSum - num]) % Modulus;
        }
    }

    u32 answer = (dp[sum / 2] * ModPow(2ull, Modulus - 2, Modulus)) % Modulus;
    cout << answer;

    return 0;
}
