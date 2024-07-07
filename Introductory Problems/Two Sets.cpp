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

    u64 n;
    cin >> n;

    u64 sum = n * (n + 1) / 2;

    if ((sum & 1) == 1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << '\n';

    u32 count1 = n / 2;
    u32 count2 = n - count1;

    u32 limit1 = n / 4;
    u32 limit2 = n - limit1 - (n & 1);

    cout << count1 << '\n';

    for (u32 num = 1; num <= limit1; num += 1)
    {
        cout << num << ' ';
    }

    for (u32 num = limit2 + 1; num <= n; num += 1)
    {
        cout << num << ' ';
    }

    cout << '\n';

    cout << count2 << '\n';

    for (u32 num = limit1 + 1; num <= limit2; num += 1)
    {
        cout << num << ' ';
    }

    return 0;
}
