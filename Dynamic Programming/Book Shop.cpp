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

struct Book
{
    u16 Price;
    u16 Pages;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 n;
    cin >> n;

    u32 x;
    cin >> x;

    vector<Book> books(n);

    for (u16 index = 0; index < n; index += 1)
    {
        cin >> books[index].Price;
    }

    for (u16 index = 0; index < n; index += 1)
    {
        cin >> books[index].Pages;
    }

    vector<u32> dp(x + 1);
    for (const Book& book : books)
    {
        for (u32 budget = x; budget >= book.Price; budget -= 1)
        {
            dp[budget] = Max(dp[budget], dp[budget - book.Price] + book.Pages);
        }
    }

    cout << dp[x];

    return 0;
}
