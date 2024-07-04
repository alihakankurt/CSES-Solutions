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

    usize q;
    cin >> q;

    while (q > 0)
    {
        q -= 1;

        u64 k;
        cin >> k;

        u64 digit = 1, coefficient = 9, num = 1;
        while (k > coefficient * num)
        {
            k -= coefficient * num;
            digit += 1;
            coefficient += 9;
            num *= 10;
        }

        k -= 1;
        u64 target = num + k / digit;
        u64 mod = digit - (k % digit);
        while (mod > 1)
        {
            target /= 10;
            mod -= 1;
        }

        cout << target % 10 << '\n';
    }

    return 0;
}
