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

    u32 maxSum = 0;
    vector<u16> coins(n);
    for (u16& coin : coins)
    {
        cin >> coin;
        maxSum += coin;
    }

    u32 count = 0;
    vector<bool> possibility(maxSum + 1, false);
    possibility[0] = true;
    for (u16 coin : coins)
    {
        for (u32 sum = maxSum; sum >= coin; sum -= 1)
        {
            if (!possibility[sum] && possibility[sum - coin])
            {
                possibility[sum] = true;
                count += 1;
            }
        }
    }

    cout << count << '\n';
    for (u32 sum = 1; sum <= maxSum; sum += 1)
    {
        if (possibility[sum])
        {
            cout << sum << ' ';
        }
    }

    return 0;
}
