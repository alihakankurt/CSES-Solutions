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

    u32 n;
    cin >> n;

    u64 totalWeight = 0;
    vector<u32> weights(n);
    for (u32 index = 0; index < n; index += 1)
    {
        cin >> weights[index];
        totalWeight += weights[index];
    }

    u64 maxWeight = 0;
    for (u32 mask = 0; mask < (1U << n); mask += 1)
    {
        u64 currentWeight = 0;
        for (u32 index = 0; index < n; index += 1)
        {
            if (((mask >> index) & 1) == 1)
            {
                currentWeight += weights[index];
            }
        }

        if (totalWeight / 2 >= currentWeight && currentWeight > maxWeight)
        {
            maxWeight = currentWeight;
        }
    }

    u32 minDifference = totalWeight - 2 * maxWeight;
    cout << minDifference;

    return 0;
}
