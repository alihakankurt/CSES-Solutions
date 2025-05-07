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

    string source, target;
    cin >> source >> target;

    auto dp = vector<vector<u16>>(source.size() + 1, vector<u16>(target.size() + 1, 0));

    for (u16 position = 1; position <= source.size(); position += 1)
    {
        dp[position][0] = position;
    }

    for (u16 position = 1; position <= target.size(); position += 1)
    {
        dp[0][position] = position;
    }

    for (u16 sourcePosition = 1; sourcePosition <= source.size(); sourcePosition += 1)
    {
        for (u16 targetPosition = 1; targetPosition <= target.size(); targetPosition += 1)
        {
            u16 substitutionCost = (source[sourcePosition - 1] == target[targetPosition - 1]) ? 0 : 1;
            dp[sourcePosition][targetPosition] = Min(
                dp[sourcePosition - 1][targetPosition] + 1,
                dp[sourcePosition][targetPosition - 1] + 1,
                dp[sourcePosition - 1][targetPosition - 1] + substitutionCost
            );
        }
    }

    cout << dp[source.size()][target.size()];

    return 0;
}
