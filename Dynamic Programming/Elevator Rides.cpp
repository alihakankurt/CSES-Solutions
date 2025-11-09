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

    u32 maxElevatorWeight;
    cin >> maxElevatorWeight;

    vector<u32> weights(n);
    for (u32& weight : weights)
    {
        cin >> weight;
    }

    u32 limit = 1u << n;
    vector<pair<u16, u32>> dp(limit);
    for (u32 mask = 1u; mask < limit; mask += 1u)
    {
        dp[mask] = {numeric_limits<u16>::max(), 0};
        for (u16 index = 0; index < n; index += 1)
        {
            if (mask & (1 << index))
            {
                auto [elevatorRides, minWeight] = dp[mask & ~(1 << index)];
                if (weights[index] <= maxElevatorWeight - minWeight)
                {
                    minWeight += weights[index];
                }
                else
                {
                    elevatorRides += 1;
                    minWeight = min(minWeight, weights[index]);
                }

                dp[mask] = min(dp[mask], {elevatorRides, minWeight});
            }
        }
    }

    u16 minElevatorRides = dp.back().first;
    if (dp.back().second > 0)
    {
        minElevatorRides += 1;
    }

    cout << minElevatorRides;

    return 0;
}
