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

    u16 t;
    cin >> t;

    for (; t > 0; t -= 1)
    {
        u16 n, a, b;
        cin >> n >> a >> b;

        if ((a + b > n) || (a == 0 && b != 0) || (a != 0 && b == 0))
        {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';

        for (u16 num = 1; num <= n; num += 1)
        {
            cout << num << ' ';
        }

        cout << '\n';

        for (u16 num = 1; num <= b; num += 1)
        {
            cout << (num + a) << ' ';
        }

        for (u16 num = 1; num <= a; num += 1)
        {
            cout << num << ' ';
        }

        for (u16 num = a + b + 1; num <= n; num += 1)
        {
            cout << num << ' ';
        }

        cout << '\n';
    }

    return 0;
}
