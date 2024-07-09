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

    vector<u32> coins(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> coins[index];
    }

    sort(coins.begin(), coins.end());

    u64 sum = 0;
    for (u32 coin : coins)
    {
        if (coin > sum + 1)
        {
            break;
        }

        sum += coin;
    }

    cout << sum + 1;

    return 0;
}
