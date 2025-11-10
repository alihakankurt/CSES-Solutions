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

constexpr u8 PositionCount = 20;
constexpr u8 DigitCount = 10;

u8 digits[PositionCount];
u64 dp[PositionCount][DigitCount + 1][2][2];

u64 countNumbers(u8 position, u8 previousDigit, bool leadingZeros, bool bound)
{
    if (position == PositionCount)
    {
        return 1;
    }

    if (dp[position][previousDigit][leadingZeros][bound] != numeric_limits<u64>::max())
    {
        return dp[position][previousDigit][leadingZeros][bound];
    }

    u64 numbers = 0;

    u8 lowerDigit = 0;
    u8 upperDigit = bound ? digits[position] : 9;

    for (u8 digit = lowerDigit; digit <= upperDigit; digit += 1)
    {
        if (digit == previousDigit && !leadingZeros)
        {
            continue;
        }

        numbers += countNumbers(position + 1, digit, leadingZeros && (digit == 0), bound && (digit == upperDigit));
    }

    dp[position][previousDigit][leadingZeros][bound] = numbers;
    return numbers;
}

u64 countNumbers(u64 num)
{
    u8 position = PositionCount;
    while (num > 0)
    {
        position -= 1;
        digits[position] = num % 10;
        num /= 10;
    }

    fill_n(&dp[0][0][0][0], sizeof(dp) / sizeof(u64), numeric_limits<u64>::max());
    return countNumbers(position, DigitCount, true, true);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u64 a, b;
    cin >> a >> b;

    cout << countNumbers(b) - (a == 0 ? 0 : countNumbers(a - 1));

    return 0;
}
