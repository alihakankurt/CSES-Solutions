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

template <typename TScalar>
inline constexpr TScalar Abs(TScalar value)
{
    return (value < 0) ? -value : value;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<i32> sticks(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> sticks[index];
    }

    sort(sticks.begin(), sticks.end());

    u64 totalCost = 0;
    i32 median = sticks[n / 2];
    for (usize index = 0; index < n; index += 1)
    {
        totalCost += Abs(median - sticks[index]);
    }

    cout << totalCost;

    return 0;
}
