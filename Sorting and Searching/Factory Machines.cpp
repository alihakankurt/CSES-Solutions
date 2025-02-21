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

template <typename TScalar, typename... TRest>
inline constexpr TScalar Min(TScalar first, TRest... rest)
{
    static_assert((is_same_v<TScalar, TRest> && ...), "All arguments must have the same type");
    if constexpr (sizeof...(rest) == 0)
        return first;
    else
        return (first < Min(rest...)) ? first : Min(rest...);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    u64 products;
    cin >> products;

    vector<u32> machines(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> machines[index];
    }

    u64 lowerTime = 0;
    u64 upperTime = 1e18;
    u64 totalTime = 0;
    while (lowerTime <= upperTime)
    {
        u64 currentTime = lowerTime + (upperTime - lowerTime) / 2;
        u64 currentProducts = 0;
        for (usize index = 0; index < n; index += 1)
        {
            currentProducts += Min(currentTime / machines[index], static_cast<u64>(1e9));
        }

        if (currentProducts >= products)
        {
            totalTime = currentTime;
            upperTime = currentTime - 1;
        }
        else
        {
            lowerTime = currentTime + 1;
        }
    }

    cout << totalTime << endl;

    return 0;
}
