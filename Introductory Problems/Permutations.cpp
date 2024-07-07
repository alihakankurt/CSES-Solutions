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

    u32 n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    for (u32 num = 2; num <= n; num += 2)
    {
        cout << num << ' ';
    }

    for (u32 num = 1; num <= n; num += 2)
    {
        cout << num << ' ';
    }

    return 0;
}
