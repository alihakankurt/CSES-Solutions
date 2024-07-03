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

template <typename TBase, typename TExponent, typename TModulus>
inline constexpr TBase ModPow(TBase base, TExponent exponent, TModulus modulus)
{
    TBase modulus_ = static_cast<TBase>(modulus);
    base %= modulus_;
    TBase result = 1;
    while (exponent > 0)
    {
        if ((exponent & 1) == 1)
            result = (result * base) % modulus_;

        base = (base * base) % modulus_;
        exponent >>= 1;
    }

    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 n;
    cin >> n;
    cout << ModPow(2ULL, n, Modulus);

    return 0;
}
