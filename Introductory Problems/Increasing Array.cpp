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
inline constexpr TScalar Max(TScalar first, TRest... rest)
{
    static_assert((is_same_v<TScalar, TRest> && ...), "All arguments must have the same type");
    if constexpr (sizeof...(rest) == 0)
        return first;
    else
        return (first > Max(rest...)) ? first : Max(rest...);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    i32 previous;
    cin >> previous;

    u64 result = 0;
    for (usize index = 1; index < n; index += 1)
    {
        i32 num;
        cin >> num;
        result += Max(0, previous - num);
        previous = Max(previous, num);
    }

    cout << result;

    return 0;
}
